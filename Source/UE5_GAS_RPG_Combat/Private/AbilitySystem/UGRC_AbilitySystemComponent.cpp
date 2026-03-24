#include "AbilitySystem/UGRC_AbilitySystemComponent.h"

void UUGRC_AbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;
	
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;
		
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UUGRC_AbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}