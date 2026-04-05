#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "UGRC_AT_ExecuteTaskOnTick.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityTaskTickDelegate, float, DeltaTime);

UCLASS()
class UE5_GAS_RPG_COMBAT_API UUGRC_AT_ExecuteTaskOnTick : public UAbilityTask
{
	GENERATED_BODY()
	
public:
	UUGRC_AT_ExecuteTaskOnTick();
	
	UFUNCTION(BlueprintCallable, Category = "UGRC|AbilityTasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	static UUGRC_AT_ExecuteTaskOnTick* ExecuteTaskOnTick(UGameplayAbility* OwningAbility);
	
	// ~ Begin UGameplayTask Interface
	virtual void TickTask(float DeltaTime) override;
	// ~ End UGameplayTask Interface
	
	UPROPERTY(BlueprintAssignable)
	FOnAbilityTaskTickDelegate OnAbilityTaskTick;
};