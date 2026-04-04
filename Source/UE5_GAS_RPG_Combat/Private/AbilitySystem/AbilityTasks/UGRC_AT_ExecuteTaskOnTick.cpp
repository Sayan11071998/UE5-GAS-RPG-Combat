#include "AbilitySystem/AbilityTasks/UGRC_AT_ExecuteTaskOnTick.h"

UUGRC_AT_ExecuteTaskOnTick::UUGRC_AT_ExecuteTaskOnTick()
{
	bTickingTask = true;
}

UUGRC_AT_ExecuteTaskOnTick* UUGRC_AT_ExecuteTaskOnTick::ExecuteTaskOnTick(UGameplayAbility* OwningAbility)
{
	UUGRC_AT_ExecuteTaskOnTick* Node = NewAbilityTask<UUGRC_AT_ExecuteTaskOnTick>(OwningAbility);
	
	return Node;
}

void UUGRC_AT_ExecuteTaskOnTick::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);
	
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnAbilityTaskTick.Broadcast(DeltaTime);
	}
	else
	{
		EndTask();
	}
}