#include "AI/UGRC_BTT_RotateToFaceTarget.h"
#include "BehaviorTree/BlackboardData.h"

UUGRC_BTT_RotateToFaceTarget::UUGRC_BTT_RotateToFaceTarget()
{
	NodeName = TEXT("Native Rotate To Face Target Actor");
	AnglePrecision = 10.f;
	RotationInterpSpeed = 5.f;
	
	bNotifyTick = true;
	bNotifyTaskFinished = true;
	bCreateNodeInstance = false;
	
	INIT_TASK_NODE_NOTIFY_FLAGS();
	
	InTargetToFaceKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, InTargetToFaceKey), AActor::StaticClass());
}

void UUGRC_BTT_RotateToFaceTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	
	if (UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		InTargetToFaceKey.ResolveSelectedKey(*BBAsset);
	}
}

uint16 UUGRC_BTT_RotateToFaceTarget::GetInstanceMemorySize() const
{
	return sizeof(FRotateToFaceTargetTaskMemory);
}

FString UUGRC_BTT_RotateToFaceTarget::GetStaticDescription() const
{
	const FString KeyDescription = InTargetToFaceKey.SelectedKeyName.ToString();
	return FString::Printf(TEXT("Smoothly rotates to face %s key until the angle precision %s is reached"), *KeyDescription, *FString::SanitizeFloat(AnglePrecision));
}