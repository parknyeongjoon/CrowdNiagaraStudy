#pragma once
#include "MassEntityElementTypes.h"
#include "BuildMassBuilderFragment.generated.h"

USTRUCT()
struct FBuildMassBuilderFragment : public FMassFragment
{
	GENERATED_BODY()

	float CurrentBuildingTime;
	uint32 HomeX;
	uint32 HomeY;
	uint8 Floor;
	uint8 MaxFloors;
	uint8 Orientation;
};
