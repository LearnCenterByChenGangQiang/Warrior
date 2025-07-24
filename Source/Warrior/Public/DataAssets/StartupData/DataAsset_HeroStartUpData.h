// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartUpData.generated.h"


/**
 * 英雄角色专用的能力配置结构体。
 * 
 * 用于指定英雄出生时应拥有的能力及其对应的输入标签（如技能槽）。
 */
USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	/** 输入标签（如 InputTag.Ability.Skill1），用于能力绑定与识别 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	/** 要授予的技能类（派生自 UWarriorGameplayAbility） */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorGameplayAbility> AbilityToGrant;

	/** 检查该配置是否有效（标签有效且技能类非空） */
	bool IsValid() const;
	
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	/**
	 * 将配置中的所有能力授予目标 AbilitySystemComponent。
	 * 
	 * @param InASCToGive 要授予能力的 AbilitySystemComponent
	 * @param ApplyLevel 授予能力的等级（默认 1）
	 */
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
	
private:
	/** 英雄出生时拥有的能力列表，支持输入绑定 */
	UPROPERTY(EditDefaultsOnly, Category="StartUpData", meta=(TitleProperty="InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;
};
