#include "BuildMassAgentRadiusInitializerProcessor.h"

#include "BuildMassBuilderTag.h"
#include "MassCommonFragments.h"

UBuildMassAgentRadiusInitializerProcessor::UBuildMassAgentRadiusInitializerProcessor()
{
	ObservedType = FAgentRadiusFragment::StaticStruct();
	Operation = EMassObservedOperation::Add;
}

void UBuildMassAgentRadiusInitializerProcessor::ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager)
{
	EntityQuery.Initialize(EntityManager);

	EntityQuery.AddRequirement<FAgentRadiusFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddTagRequirement<FBuildMassBuilderTag>(EMassFragmentPresence::All);

	EntityQuery.RegisterWithProcessor(*this);
}

void UBuildMassAgentRadiusInitializerProcessor::Execute(FMassEntityManager& EntityManager,
	FMassExecutionContext& Context)
{
	
}
