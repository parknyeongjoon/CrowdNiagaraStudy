#pragma once

#include "CoreMinimal.h"
#include "MassEntityElementTypes.h"
#include "NiagaraSystem.h"
#include "MassNiagaraSharedSettings.generated.h"

USTRUCT()
struct FMassNiagaraSharedSettings : public FMassConstSharedFragment
{
	GENERATED_BODY()

	UPROPERTY()
	TSoftObjectPtr<UNiagaraSystem> DefaultNiagaraSystem = nullptr;

	UPROPERTY()
	TArray<TSoftObjectPtr<UStaticMesh>> MeshVariances;

	UPROPERTY()
	float DefaultSpawnInterval = 2.0f;
};