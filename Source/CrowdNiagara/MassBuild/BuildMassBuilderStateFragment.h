#pragma once
#include "BuildMassBuilderFragment.h"
#include "BuildMassBuilderStateFragment.generated.h"

UENUM()
enum class EBuildMassBuilderStates
{
	
};

USTRUCT()
struct FBuildMassBuilderStateFragment : public FMassFragment
{
	GENERATED_BODY()

	UPROPERTY()
	EBuildMassBuilderStates CurrentState;
	UPROPERTY()
	bool bArrived;
};
