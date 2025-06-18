#pragma once
#include "BuildMassGridSubsystem.generated.h"

constexpr int32 GridDimensions = 100;

USTRUCT()
struct FBuildMassGridCellContent
{
	GENERATED_BODY()
};

UCLASS()
class UBuildMassGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	typedef FBuildMassGridCellContent BuildMassGrid[GridDimensions][GridDimensions];
	typedef FBuildMassGridCellContent BuildMassSubGrid[3][3];

private:
	BuildMassGrid Grid;
};
