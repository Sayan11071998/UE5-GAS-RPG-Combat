#include "Components/Combat/UGRC_EnemyCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "UGRC_GameplayTags.h"

void UUGRC_EnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor)) return;
	
	OverlappedActors.Add(HitActor);
	
	// TODO: Implement Block Check
	bool bIsValidBlock = false;
	
	const bool bIsPlayerBlocking = false;
	const bool bIsMyAttackUnblockable = false;
	
	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		// TODO: Check if the block is valid
	}
	
	FGameplayEventData EentData;
	EentData.Instigator = GetOwningPawn();
	EentData.Target = HitActor;
	
	if (bIsValidBlock)
	{
		// TODO: Handle Successful Block
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn(),
			UGRC_GameplayTags::Shared_Event_MeleeHit,
			EentData
		);
	}
}