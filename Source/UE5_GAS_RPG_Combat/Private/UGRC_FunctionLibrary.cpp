#include "UGRC_FunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/UGRC_AbilitySystemComponent.h"

TObjectPtr<UUGRC_AbilitySystemComponent> UUGRC_FunctionLibrary::NativeGetWarriorASCFromActor(TObjectPtr<AActor> InActor)
{
	check(InActor);
	
	return CastChecked<UUGRC_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

bool UUGRC_FunctionLibrary::NativeDoesActorHaveTag(TObjectPtr<AActor> InActor, FGameplayTag TagToCheck)
{
	UUGRC_AbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UUGRC_FunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UUGRC_AbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	
	if (ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UUGRC_FunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UUGRC_AbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

void UUGRC_FunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck,
	EUGRC_ConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EUGRC_ConfirmType::Yes : EUGRC_ConfirmType::No;
}