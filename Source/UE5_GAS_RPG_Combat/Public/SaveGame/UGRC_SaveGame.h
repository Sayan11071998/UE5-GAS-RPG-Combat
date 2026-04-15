#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CharacterTypes/UGRC_EnumTypes.h"
#include "UGRC_SaveGame.generated.h"

UCLASS()
class UE5_GAS_RPG_COMBAT_API UUGRC_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	EUGRC_GameDifficulty SavedCurrentGameDifficulty;
};