// Fill out your copyright notice in the Description page of Project Settings.

#include "MassNiagara/MassNiagaraProcessor.h"
#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "MassNiagaraSharedSettings.h"
#include "MassNiagaraSpawnFragment.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraEmitter.h"
#include "NiagaraMeshRendererProperties.h"
#include "NiagaraComponent.h"

UMassNiagaraProcessor::UMassNiagaraProcessor()
{
	UE_LOG(LogMass, Display, TEXT("MassNiagaraProcessor Constructor"))

	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UMassNiagaraProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	UE_LOG(LogMass, Display, TEXT("MassNiagaraProcessor Configure Queries"))

	EntityQuery.Initialize(EntityManager);
	
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FMassNiagaraSpawnFragment>(EMassFragmentAccess::ReadWrite);

	EntityQuery.AddConstSharedRequirement<FMassNiagaraSharedSettings>(EMassFragmentPresence::All);
	EntityQuery.RegisterWithProcessor(*this);
}

void UMassNiagaraProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	UE_LOG(LogMass, Display, TEXT("MassNiagaraProcessor For Each Entity"))
	TArray<FNiagaraSpawnCommand> SpawnCommands;
	EntityQuery.ForEachEntityChunk(Context, [this, &SpawnCommands](FMassExecutionContext& Context)
	{
		// SharedFragment 가져오기
		const FMassNiagaraSharedSettings& SharedSettings = Context.GetConstSharedFragment<FMassNiagaraSharedSettings>();
		
		const auto TransformList = Context.GetFragmentView<FTransformFragment>();
		auto NiagaraList = Context.GetMutableFragmentView<FMassNiagaraSpawnFragment>();
        
		for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
		{
			UE_LOG(LogMass, Display, TEXT("Mass Entity for Entity %d"), EntityIndex)
			const FTransform& Transform = TransformList[EntityIndex].GetTransform();
			FMassNiagaraSpawnFragment& NiagaraFragment = NiagaraList[EntityIndex];

			// Mesh Variance 중 하나 랜덤 생성
			if (!NiagaraFragment.NiagaraSystem.IsValid())
			{
				NiagaraFragment.NiagaraSystem = SharedSettings.DefaultNiagaraSystem;
				NiagaraFragment.SpawnCooldown = SharedSettings.DefaultSpawnInterval;

				if (SharedSettings.MeshVariances.Num() <= 0)
				{
					NiagaraFragment.SpawnMeshIndex = 0;  // 기본값
				}
				else
				{
					NiagaraFragment.SpawnMeshIndex = 
						FMath::RandRange(0, SharedSettings.MeshVariances.Num() - 1);
				}
			}
			
			NiagaraFragment.SpawnCooldown -= Context.GetDeltaTimeSeconds();
			
			if (NiagaraFragment.NiagaraSystem &&
				NiagaraFragment.bShouldSpawn &&
				NiagaraFragment.SpawnCooldown <= 0.0f)
			{
				// 즉시 스폰하지 않고 커맨드에 추가
				FNiagaraSpawnCommand Command;
				Command.NiagaraSystem = NiagaraFragment.NiagaraSystem;
				Command.Location = Transform.GetLocation();
				Command.Rotation = Transform.GetRotation().Rotator();
				Command.CustomMesh = SharedSettings.MeshVariances[NiagaraFragment.SpawnMeshIndex];

				SpawnCommands.Add(Command);
                
				NiagaraFragment.bShouldSpawn = true;
				NiagaraFragment.SpawnCooldown = SharedSettings.DefaultSpawnInterval;
			}
		}
	});

	if (!SpawnCommands.IsEmpty())
	{
		AsyncTask(ENamedThreads::GameThread, [SpawnCommands, this]()
		{
			for (const FNiagaraSpawnCommand& Command : SpawnCommands)
			{
				if (IsValid(GetWorld()) && Command.NiagaraSystem.IsValid())
				{
					UNiagaraComponent* NiagaraComponent = 
						UNiagaraFunctionLibrary::SpawnSystemAtLocation(
							GetWorld(),
							Command.NiagaraSystem.Get(),
							Command.Location,
							Command.Rotation
						);
					
					if (IsValid(NiagaraComponent) && Command.CustomMesh.Get())
					{
						NiagaraComponent->SetVariableObject(FName("User.CustomMesh"), Command.CustomMesh.Get());

						const FNiagaraParameterStore& ParamStore = NiagaraComponent->GetOverrideParameters();
						
						NiagaraComponent->MarkRenderStateDirty();
						NiagaraComponent->ResetSystem();
						NiagaraComponent->ReinitializeSystem();
						NiagaraComponent->Activate(true);
					}
				}
			}
		});
	}
}
