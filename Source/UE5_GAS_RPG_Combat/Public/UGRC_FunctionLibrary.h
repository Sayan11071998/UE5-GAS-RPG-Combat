#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UGRC_FunctionLibrary.generated.h"

class UUGRC_AbilitySystemComponent;

UENUM()
enum class EUGRC_ConfirmType : uint8
{
	Yes,
	No
};

UCLASS()
class UE5_GAS_RPG_COMBAT_API UUGRC_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static TObjectPtr<UUGRC_AbilitySystemComponent> NativeGetWarriorASCFromActor(TObjectPtr<AActor> InActor);
	static bool NativeDoesActorHaveTag(TObjectPtr<AActor> InActor, FGameplayTag TagToCheck);
	
	UFUNCTION(BlueprintCallable, Category = "UGRC|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);
	
	UFUNCTION(BlueprintCallable, Category = "UGRC|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);
	
	UFUNCTION(BlueprintCallable, Category = "UGRC|FunctionLibrary", meta =(DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EUGRC_ConfirmType& OutConfirmType);
};