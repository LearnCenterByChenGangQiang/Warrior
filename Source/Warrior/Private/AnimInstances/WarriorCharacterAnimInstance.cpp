// ChenGangQiang All rights Reserved.


#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	// 尝试将动画拥有者转换为自定义角色类型
	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());
	// 如果成功，则获取其移动组件
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// 若角色或其移动组件无效，则不进行更新
	if (!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	// 获取角色的二维速度（忽略Z轴），用于控制奔跑/行走等动画
	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	// 判断当前是否有加速度，用于判断是否移动中
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
}
