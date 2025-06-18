// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MassNiagaraProcessor.generated.h"

class UNiagaraSystem;
/**
 * 
 */
USTRUCT()
struct FNiagaraSpawnCommand
{
	GENERATED_BODY()
    
	TSoftObjectPtr<UNiagaraSystem> NiagaraSystem;
	TSoftObjectPtr<UStaticMesh> CustomMesh;
	FVector Location;
	FRotator Rotation;
};

UCLASS()
class CROWDNIAGARA_API UMassNiagaraProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UMassNiagaraProcessor();

protected:
	virtual void ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager) override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};
