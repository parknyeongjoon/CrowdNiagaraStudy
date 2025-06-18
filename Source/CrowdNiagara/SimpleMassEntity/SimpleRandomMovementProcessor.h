#pragma once
#include "MassProcessor.h"
#include "MassEntityQuery.h"
#include "SimpleRandomMOvementProcessor.generated.h"

UCLASS()
class USimpleRandomMovementProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	USimpleRandomMovementProcessor();

protected:
	virtual void ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager) override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};
