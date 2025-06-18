#pragma once
#include "MassProcessor.h"
#include "AdvancedRandomMovementProcessor.generated.h"

UCLASS()
class UAdvancedRandomMovementProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	UAdvancedRandomMovementProcessor();
	
	virtual void ConfigureQueries(const TSharedRef<FMassEntityManager>& EntityManager) override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};