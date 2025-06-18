#pragma once
#include "BuildMassBuildingSubsystem.h"
#include "BuildMassGridSubsystem.h"
#include "MassProcessor.h"
#include "BuildMassBuilderProcessor.generated.h"

UCLASS()
class UBuildMassBuilderProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	TObjectPtr<UBuildMassGridSubsystem> GridSubsystem;
	TObjectPtr<UBuildMassBuildingSubsystem> BuildingSubsystem;
};
