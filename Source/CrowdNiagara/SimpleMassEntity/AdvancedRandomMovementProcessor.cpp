#include "AdvancedRandomMovementProcessor.h"

#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "MassNavigationFragments.h"
#include "MassMovementFragments.h"

UAdvancedRandomMovementProcessor::UAdvancedRandomMovementProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UAdvancedRandomMovementProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	EntityQuery.Initialize(EntityManager);
	
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FMassMoveTargetFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddConstSharedRequirement<FMassMovementParameters>(EMassFragmentPresence::All);
	
	EntityQuery.RegisterWithProcessor(*this);
}

void UAdvancedRandomMovementProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	UE_LOG(LogMass, Display, TEXT("Advance Random Execute"))
	EntityQuery.ForEachEntityChunk(Context, [this](FMassExecutionContext& Context)
	{
		const TConstArrayView<FTransformFragment> TransformsList = Context.GetFragmentView<FTransformFragment>();
		const TArrayView<FMassMoveTargetFragment> NavTargetsList = Context.GetMutableFragmentView<FMassMoveTargetFragment>();
		const FMassMovementParameters& MovementParams = Context.GetConstSharedFragment<FMassMovementParameters>();

		for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
		{
			UE_LOG(LogMass, Display, TEXT("Entity for Entity %d"), EntityIndex)
			const FTransform& Transform = TransformsList[EntityIndex].GetTransform();
			FMassMoveTargetFragment& MoveTarget = NavTargetsList[EntityIndex];

			FVector CurrentLocation = Transform.GetLocation();
			FVector TargetVector = MoveTarget.Center - Transform.GetLocation();
			TargetVector.Z = 0;
			MoveTarget.DistanceToGoal = TargetVector.Size();
			MoveTarget.Forward = TargetVector.GetSafeNormal();

			if (MoveTarget.DistanceToGoal <= 20.f || MoveTarget.Center == FVector::ZeroVector)
			{
				MoveTarget.Center = FVector(FMath::RandRange(-1.f, 1.f) * 1000.f, FMath::RandRange(-1.f, 1.f) * 1000.f, CurrentLocation.Z);
				MoveTarget.DistanceToGoal = (MoveTarget.Center - Transform.GetLocation()).Size();
				MoveTarget.Forward = (MoveTarget.Center - Transform.GetLocation()).GetSafeNormal();
				MoveTarget.DesiredSpeed = FMassInt16Real(MovementParams.DefaultDesiredSpeed);
			}
		}
	});
}
