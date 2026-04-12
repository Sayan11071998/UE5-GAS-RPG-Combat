#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterTypes/UGRC_EnumTypes.h"
#include "UGRC_GameModeBase.generated.h"

UCLASS()
class UE5_GAS_RPG_COMBAT_API AUGRC_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AUGRC_GameModeBase();
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	EUGRC_GameDifficulty CurrentGameDifficulty;
	
public:
	FORCEINLINE EUGRC_GameDifficulty GetCurrentGameDifficulty() const { return CurrentGameDifficulty; }
};