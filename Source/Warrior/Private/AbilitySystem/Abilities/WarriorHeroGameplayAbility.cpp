// ChenGangQiang All rights Reserved.


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		// 尝试将 AvatarActor 转为 AWarriorHeroCharacter
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	// 如果转换成功，返回缓存的角色指针
	return CachedWarriorHeroCharacter.IsValid() ? CachedWarriorHeroCharacter.Get() : nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		// 尝试将 AvatarActor 转为 AWarriorHeroController
		CachedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->AvatarActor);
	}
	// 如果转换成功，返回缓存的控制器指针
	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	// 先通过封装方法获取角色，再获取其战斗组件
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
