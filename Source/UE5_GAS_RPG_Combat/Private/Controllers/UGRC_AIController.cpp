#include "Controllers/UGRC_AIController.h"
#include "Navigation/CrowdFollowingComponent.h"

#include "UGRC_DebugHelper.h"

AUGRC_AIController::AUGRC_AIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
	if (UCrowdFollowingComponent* CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		Debug::Print(TEXT("UCrowdFollowingComponent valid"));
	}
}