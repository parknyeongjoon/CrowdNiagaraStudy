#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "SimpleRandomMovementTrait.generated.h"

UCLASS()
class CROWDNIAGARA_API USimpleRandomMovementTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
