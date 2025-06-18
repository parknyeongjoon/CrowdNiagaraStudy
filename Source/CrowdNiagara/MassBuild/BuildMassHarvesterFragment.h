#pragma once
#include "CoreMinimal.h"
#include "BuildMassBuilderStateFragment.h"
#include "BuildMassHarvesterFragment.generated.h"

UENUM()
enum class EBuildMassHarvesterResources
{
	
};

USTRUCT()
struct FBuildMassHarvesterFragment : public FMassFragment
{
	GENERATED_BODY()

	float CurrentGatheringTime;
	uint32 TargetCellX;
	uint32 TargetCellY;
	EBuildMassHarvesterResources DesiredResources;
	uint8 ResourcesGathered;
};
