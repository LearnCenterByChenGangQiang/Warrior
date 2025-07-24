// ChenGangQiang All rights Reserved.


#include "DataAssets/StartupData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

/**
 * 校验能力配置是否有效。
 * 
 * @return 标签有效 且 技能类非空时返回 true，否则返回 false。
 */
bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}


/**
 * 将英雄的初始能力授予指定的能力系统组件（ASC）。
 * 
 * 同时会将每个能力与其输入标签绑定（添加到 AbilitySpec 的 DynamicSpecSourceTags）。
 */
void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
	int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);
	for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		// 构建能力规格描述
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		// 将输入标签作为 DynamicSpecSourceTags 添加到该能力中
		//AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		// 授予能力到目标 ASC
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
