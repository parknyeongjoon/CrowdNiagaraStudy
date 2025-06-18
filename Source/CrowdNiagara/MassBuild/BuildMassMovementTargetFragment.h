#pragma once
#include "BuildMassBuilderFragment.h"
#include "BuildMassGridSubsystem.h"
#include "BuildMassMovementTargetFragment.generated.h"

USTRUCT()
struct FBuildMassMovementTargetFragment : public FMassFragment
{
	GENERATED_BODY()

	FVector TargetLocation;
	uint32 CachedGridX;
	uint32 CachedGridY;
	UBuildMassGridSubsystem::BuildMassSubGrid CachedGrid;
	bool bStartGoing;
};
