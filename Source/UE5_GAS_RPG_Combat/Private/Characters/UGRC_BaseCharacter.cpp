#include "Characters/UGRC_BaseCharacter.h"

AUGRC_BaseCharacter::AUGRC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	GetMesh()->bReceivesDecals = false;
}