// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbility.generated.h"

UENUM(Blueprintable)
enum class EWarriorAbilityActivationPolicy : uint8
{
	/** 玩家主动触发（例如按键）时激活能力 */
	OnTriggered,

	/** 能力赋予时立即激活（例如拾取后立即生效） */
	OnGiven
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility interface
	// 能力被添加到 AbilitySystemComponent 时调用
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec);
	// 能力结束时调用（主动结束或被取消）
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);
	//~ End UGameplayAbility interface

	/** 决定该能力的激活策略（例如是否自动激活） */
	UPROPERTY(EditDefaultsOnly, Category = "WarriorAbility")
	EWarriorAbilityActivationPolicy AbilityActivationPolicy = EWarriorAbilityActivationPolicy::OnTriggered;
};
