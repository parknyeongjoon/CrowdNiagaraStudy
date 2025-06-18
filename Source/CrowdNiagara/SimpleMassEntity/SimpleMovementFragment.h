#pragma once
#include "MassEntityElementTypes.h"
#include "SimpleMovementFragment.generated.h"

USTRUCT()
struct FSimpleMovementFragment : public FMassFragment
{
	GENERATED_BODY()
	FVector Target;
};
