// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()

public:
	/** 动画初始化时调用（首次运行） */
	virtual void NativeInitializeAnimation() override;

	/** 每帧更新动画状态（线程安全） */
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	/** 拥有该动画实例的英雄角色指针，仅适用于英雄角色 */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	AWarriorHeroCharacter* OwningHeroCharacter;

	/** 是否应该进入放松（Relax）状态，用于站立不动太久时的动画切换 */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	/** 进入放松状态所需的最小时间（单位：秒） */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.0f;

	/** 当前角色处于静止状态的累计时间 */
	float IdleElapsedTime;
};
