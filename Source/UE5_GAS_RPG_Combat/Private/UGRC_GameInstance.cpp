#include "UGRC_GameInstance.h"

TSoftObjectPtr<UWorld> UUGRC_GameInstance::GetGameLevelByTag(FGameplayTag InTag)
{
	for (const FUGRC_GameLevelSet& GameLevelSet : GameLevelSets)
	{
		if (!GameLevelSet.IsValid()) continue;
		
		if (GameLevelSet.LevelTag == InTag)
		{
			return GameLevelSet.Level;
		}
	}
	
	return TSoftObjectPtr<UWorld>();
}