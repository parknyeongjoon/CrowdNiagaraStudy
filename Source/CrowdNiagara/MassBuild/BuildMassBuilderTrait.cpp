#include "BuildMassBuilderTrait.h"

#include "BuildMassBuilderStateFragment.h"
#include "BuildMassBuilderTag.h"
#include "MassEntityTemplateRegistry.h"

void UBuildMassBuilderTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	BuildContext.AddFragment<FBuildMassBuilderStateFragment>();
	BuildContext.AddFragment<FBuildMassBuilderFragment>();
	BuildContext.AddTag<FBuildMassBuilderTag>();
}
