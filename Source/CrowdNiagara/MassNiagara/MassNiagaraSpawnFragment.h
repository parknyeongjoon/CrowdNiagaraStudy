#pragma once
#include "MassEntityTypes.h"
#include "NiagaraSystem.h"
#include "MassNiagaraSpawnFragment.generated.h"

USTRUCT()
struct FMassNiagaraSpawnFragment : public FMassFragment
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TSoftObjectPtr<UNiagaraSystem> NiagaraSystem;

	UPROPERTY()
	int32 SpawnMeshIndex = 0;
    
	UPROPERTY()
	FVector SpawnLocation = FVector::ZeroVector;
    
	UPROPERTY()
	bool bShouldSpawn = true;
    
	UPROPERTY()
	float SpawnCooldown = 0.0f;
};