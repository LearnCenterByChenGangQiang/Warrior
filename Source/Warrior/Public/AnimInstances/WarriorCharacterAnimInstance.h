// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class AWarriorBaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	/** 动画初始化时调用（首次运行） */
	virtual void NativeInitializeAnimation() override;

	/** 每帧更新动画状态（线程安全） */
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	/** 拥有该动画实例的角色 */
	UPROPERTY()
	AWarriorBaseCharacter* OwningCharacter;

	/** 角色的移动组件 */
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	/** 当前地面速度（用于动画Blend） */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	/** 当前是否具有加速度（用于判断移动状态） */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
