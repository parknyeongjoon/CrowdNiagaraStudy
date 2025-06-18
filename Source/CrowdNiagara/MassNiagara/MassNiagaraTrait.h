// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "NiagaraSystem.h"
#include "MassNiagaraTrait.generated.h"

UCLASS()
class CROWDNIAGARA_API UMassNiagaraTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Niagara")
	TSoftObjectPtr<UNiagaraSystem> DefaultNiagaraSystem;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	TArray<TSoftObjectPtr<UStaticMesh>> MeshVariances;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	float DefaultSpawnInterval = 2.0f;

protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
