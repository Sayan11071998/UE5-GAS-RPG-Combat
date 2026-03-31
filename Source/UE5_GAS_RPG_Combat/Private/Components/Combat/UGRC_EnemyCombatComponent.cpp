#include "Components/Combat/UGRC_EnemyCombatComponent.h"

#include "UGRC_DebugHelper.h"

void UUGRC_EnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (HitActor)
	{
		Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" is hitting ") + HitActor->GetActorNameOrLabel());
	}
}