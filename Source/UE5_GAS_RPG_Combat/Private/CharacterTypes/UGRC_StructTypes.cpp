#include "CharacterTypes/UGRC_StructTypes.h"
#include "AbilitySystem/Abilities/UGRC_GameplayAbility.h"

bool FUGRC_HeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}