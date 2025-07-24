// ChenGangQiang All rights Reserved.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"

#include "WarriorDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,
                                                 AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	// 检查：不能重复注册相同标签的武器
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("Weapon with tag %s is already registered!"), *InWeaponTagToRegister.ToString());
	// 检查：武器实例不能为空
	check(InWeaponToRegister)

	// 添加到映射表中：标签 => 武器
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	// 如果需要设为当前装备武器，记录该标签
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	// 打印调试信息，便于开发中查看注册过程
	const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered with tag: %s"),*InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
	
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	// 如果 Map 中包含该标签
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		// 查找对应的武器指针（TObjectPtr 包装过的）
		if (const TObjectPtr<AWarriorWeaponBase>* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			// 返回原始 UObject 指针（TObjectPtr::Get()）
			return FoundWeapon->Get();
		}
	}
	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	// 当前未装备任何武器，标签无效
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	// 复用已有函数，通过标签查找当前装备武器
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
