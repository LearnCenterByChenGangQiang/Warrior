// ChenGangQiang All rights Reserved.


#include "DataAssets/StartupData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
	int32 ApplyLevel)
{
	// 确保目标 ASC 不为空
	check(InASCToGive);

	// 赋予立即激活类能力
	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);

	// 赋予被动/监听类能力
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	// 无需赋予时提前返回
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}
	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		// 忽略无效类
		if (!Ability) continue;

		// 构建能力规格
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor(); // 设置来源
		AbilitySpec.Level = ApplyLevel; // 设置能力等级

		// 调用 GAS 的 API 赋予能力
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
