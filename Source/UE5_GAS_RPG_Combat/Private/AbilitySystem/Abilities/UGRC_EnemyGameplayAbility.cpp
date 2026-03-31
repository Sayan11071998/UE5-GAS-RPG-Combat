#include "AbilitySystem/Abilities/UGRC_EnemyGameplayAbility.h"
#include "Characters/UGRC_EnemyCharacter.h"
#include "AbilitySystem/UGRC_AbilitySystemComponent.h"
#include "UGRC_GameplayTags.h"

AUGRC_EnemyCharacter* UUGRC_EnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedUGRCEnemyCharacter.IsValid())
	{
		CachedUGRCEnemyCharacter = Cast<AUGRC_EnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedUGRCEnemyCharacter.IsValid() ? CachedUGRCEnemyCharacter.Get() : nullptr;
}

UUGRC_EnemyCombatComponent* UUGRC_EnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}

FGameplayEffectSpecHandle UUGRC_EnemyGameplayAbility::MakeEnemyDamageEffectSpecHandle(
	TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat)
{
	check(EffectClass);
	
	FGameplayEffectContextHandle ContextHandle = GetUGRCAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());
	
	FGameplayEffectSpecHandle EffectSpecHandle = GetUGRCAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);
	
	EffectSpecHandle.Data->SetSetByCallerMagnitude(UGRC_GameplayTags::Shared_SetByCaller_BaseDamage, InDamageScalableFloat.GetValueAtLevel(GetAbilityLevel()));

	return EffectSpecHandle;
}