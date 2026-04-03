#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UGRC_BaseAnimInstance.generated.h"

struct FGameplayTag;

UCLASS()
class UE5_GAS_RPG_COMBAT_API UUGRC_BaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	bool DoesOwnerHasTag(FGameplayTag TagToCheck) const;
};