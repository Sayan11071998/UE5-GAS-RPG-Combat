#include "AbilitySystem/Abilities/UGRC_HeroGameplayAbility.h"
#include "Characters/UGRC_HeroCharacter.h"
#include "Controllers/UGRC_HeroController.h"

AUGRC_HeroCharacter* UUGRC_HeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedUGRCHeroCharacter.IsValid())
	{
		CachedUGRCHeroCharacter = Cast<AUGRC_HeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedUGRCHeroCharacter.IsValid() ? CachedUGRCHeroCharacter.Get() : nullptr;
}

AUGRC_HeroController* UUGRC_HeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedUGRCHeroController.IsValid())
	{
		CachedUGRCHeroController = Cast<AUGRC_HeroController>(CurrentActorInfo->PlayerController);
	}
	
	return CachedUGRCHeroController.IsValid() ? CachedUGRCHeroController.Get() : nullptr;
}

UUGRC_HeroCombatComponent* UUGRC_HeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}