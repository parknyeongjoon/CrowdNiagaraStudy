#include "AdvancedRandomMovementTrait.h"

#include "MassEntityTemplateRegistry.h"
#include "MassNavigationFragments.h"

void UAdvancedRandomMovementTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext,
                                                 const UWorld& World) const
{
	BuildContext.AddFragment<FMassMoveTargetFragment>();
}
