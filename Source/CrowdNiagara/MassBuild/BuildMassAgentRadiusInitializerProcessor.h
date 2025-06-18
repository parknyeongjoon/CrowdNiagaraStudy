#pragma once
#include "MassObserverProcessor.h"
#include "BuildMassAgentRadiusInitializerProcessor.generated.h"

UCLASS()
class UBuildMassAgentRadiusInitializerProcessor : public UMassObserverProcessor
{
	GENERATED_BODY()
public:
	UBuildMassAgentRadiusInitializerProcessor();

protected:
	virtual void ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager) override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};
