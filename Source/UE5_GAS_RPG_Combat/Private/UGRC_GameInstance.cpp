#include "UGRC_GameInstance.h"
#include "MoviePlayer.h"

void UUGRC_GameInstance::Init()
{
	Super::Init();
	
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UUGRC_GameInstance::OnPreLoadMap);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UUGRC_GameInstance::OnDestinationWorldLoaded);
}

TSoftObjectPtr<UWorld> UUGRC_GameInstance::GetGameLevelByTag(FGameplayTag InTag) const
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

void UUGRC_GameInstance::OnPreLoadMap(const FString& MapName)
{
	FLoadingScreenAttributes LoadingScreenAttributes;
	LoadingScreenAttributes.bAutoCompleteWhenLoadingCompletes = true;
	LoadingScreenAttributes.MinimumLoadingScreenDisplayTime = 2.f;
	LoadingScreenAttributes.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
	
	GetMoviePlayer()->SetupLoadingScreen(LoadingScreenAttributes);
}

void UUGRC_GameInstance::OnDestinationWorldLoaded(UWorld* LoadedWorld)
{
	GetMoviePlayer()->StopMovie();
}