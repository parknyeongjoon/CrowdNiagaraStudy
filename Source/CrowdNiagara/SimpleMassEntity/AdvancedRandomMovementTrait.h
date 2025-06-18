#pragma once
#include "MassEntityTraitBase.h"
#include "AdvancedRandomMovementTrait.generated.h"

UCLASS()
class UAdvancedRandomMovementTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()
public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
