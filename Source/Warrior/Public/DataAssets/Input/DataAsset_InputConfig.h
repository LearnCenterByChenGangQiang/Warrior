// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;


/**
 * 单个输入动作配置结构体，用于将一个输入标签（GameplayTag）与一个输入动作（UInputAction）绑定。
 */
USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()

public:
	/** 输入标签，用于标识输入功能，例如 "InputTag.Move"、"InputTag.Jump" */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	/** 对应的输入动作（Enhanced Input 中的 UInputAction） */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;

	/**
	 * 判断当前配置是否有效（即标签有效且动作不为空）。
	 */
	bool IsValid() const
	{
		return InputTag.IsValid() && InputAction;
	}
};


/**
 * 输入配置数据资源（DataAsset）。
 * 
 * 用于集中管理所有角色输入配置，包括：
 * - 默认输入映射（MappingContext）
 * - 原生输入（如系统移动/视角）
 * - 能力输入（如技能绑定）
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 默认的输入映射上下文，通常用于初始化时添加 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	/** 原生输入动作配置列表，如 Move、Look、Jump */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	/**
	 * 根据输入标签查找对应的原生输入动作。
	 * 
	 * @param InputTag 输入标签
	 * @return 匹配到的 UInputAction，如果没有则返回 nullptr
	 */
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InputTag) const;

	/** 能力输入动作配置列表，用于绑定 GameplayAbility 的触发输入（如技能释放） */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputTag"))
	TArray<FWarriorInputActionConfig> AbilityInputActions;
	
};
