// ChenGangQiang All rights Reserved.


#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// 若成功获取基础角色，则尝试转为英雄角色
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	// 如果角色有加速度（移动中），则重置计时器和状态
	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.0f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		// 累加静止时间，并判断是否应进入放松状态
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
