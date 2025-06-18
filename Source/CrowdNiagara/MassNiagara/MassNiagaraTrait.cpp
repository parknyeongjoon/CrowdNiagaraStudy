// Fill out your copyright notice in the Description page of Project Settings.

#include "MassNiagara/MassNiagaraTrait.h"

#include "MassCommonFragments.h"
#include "MassEntityTemplateRegistry.h"
#include "MassNiagaraSharedSettings.h"
#include "MassNiagaraSpawnFragment.h"

void UMassNiagaraTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	UE_LOG(LogMass, Display, TEXT("Mass Niagara Build Template"))
	// Fragment 추가
	BuildContext.AddFragment<FMassNiagaraSpawnFragment>();
	BuildContext.AddFragment<FTransformFragment>();

	FMassEntityManager& EntityManager = UE::Mass::Utils::GetEntityManagerChecked(World);
	
	// SharedFragment 데이터 생성
	FMassNiagaraSharedSettings SharedSettings;
	SharedSettings.DefaultNiagaraSystem = DefaultNiagaraSystem;
	SharedSettings.DefaultSpawnInterval = DefaultSpawnInterval;
	SharedSettings.MeshVariances = MeshVariances;

	// 기존 SharedFragment 검색 또는 새로 생성
	FConstSharedStruct MySharedFragment = EntityManager.GetOrCreateConstSharedFragment<FMassNiagaraSharedSettings>(SharedSettings);
    
	// BuildContext에 추가
	BuildContext.AddConstSharedFragment(MySharedFragment);
}
