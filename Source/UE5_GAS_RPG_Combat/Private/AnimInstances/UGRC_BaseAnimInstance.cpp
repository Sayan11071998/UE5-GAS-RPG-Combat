#include "AnimInstances/UGRC_BaseAnimInstance.h"
#include "GameplayTagContainer.h"
#include "UGRC_FunctionLibrary.h"

bool UUGRC_BaseAnimInstance::DoesOwnerHasTag(FGameplayTag TagToCheck) const
{
	if (APawn* OwningPawn = TryGetPawnOwner())
	{
		return UUGRC_FunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
	}
	
	return false;
}