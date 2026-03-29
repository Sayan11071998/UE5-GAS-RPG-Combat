#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UGRC_AIController.generated.h"

UCLASS()
class UE5_GAS_RPG_COMBAT_API AUGRC_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AUGRC_AIController(const FObjectInitializer& ObjectInitializer);
};