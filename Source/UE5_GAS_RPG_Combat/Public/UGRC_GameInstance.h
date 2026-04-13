#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/GameInstance.h"
#include "UGRC_GameInstance.generated.h"

USTRUCT(BlueprintType)
struct FUGRC_GameLevelSet
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, meta = (Categories = "GameData.Level"))
	FGameplayTag LevelTag;
	
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> Level;
	
	bool IsValid() const
	{
		return LevelTag.IsValid() && !Level.IsNull();
	}
};

UCLASS()
class UE5_GAS_RPG_COMBAT_API UUGRC_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (GameplayTahFilter = "GameData.Level"))
	TSoftObjectPtr<UWorld> GetGameLevelByTag(FGameplayTag InTag);
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FUGRC_GameLevelSet> GameLevelSets;
};