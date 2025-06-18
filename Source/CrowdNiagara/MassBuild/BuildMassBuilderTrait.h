#pragma once
#include "MassEntityTraitBase.h"
#include "BuildMassBuilderTrait.generated.h"

UCLASS()
class UBuildMassBuilderTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()
public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
