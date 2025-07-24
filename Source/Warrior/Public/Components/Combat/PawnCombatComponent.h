// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorWeaponBase;
/**
 * 
 */
UCLASS()
class WARRIOR_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	/**
	 * 注册一个生成出来的武器对象。
	 * 
	 * @param InWeaponTagToRegister 武器对应的 GameplayTag（如 Primary、Secondary）
	 * @param InWeaponToRegister    要注册的武器对象（AWarriorWeaponBase 实例）
	 * @param bRegisterAsEquippedWeapon 是否立即设置为当前装备的武器（默认 false）
	 * 
	 * 示例用途：角色拾取、生成武器后调用，建立标签与武器实例的映射关系。
	 */
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	/**
	 * 根据标签查找角色当前携带的武器。
	 * 
	 * @param InWeaponTagToGet 要查询的武器标签
	 * @return 若找到，返回对应武器指针；否则返回 nullptr
	 * 
	 * 示例用途：在动画事件或技能中，根据标签触发对应武器逻辑。
	 */
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase*GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	/** 当前装备的武器标签（如 "Weapon.Primary"），用于状态记录与 UI 显示 */
	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	/**
	 * 获取当前装备的武器实例。
	 * 
	 * @return 若当前标签有效且对应武器存在，返回该武器；否则返回 nullptr。
	 * 
	 * 示例用途：攻击逻辑、动画蓝图中访问当前武器。
	 */
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorWeaponBase* GetCharacterCurrentEquippedWeapon() const;
	
private:
	/**
	 * 武器存储映射表：通过 GameplayTag 快速索引当前角色拥有的武器。
	 * 
	 * 注意：使用 TObjectPtr 是为了避免原始指针在 GC 后失效的问题。
	 */
	TMap<FGameplayTag, TObjectPtr<AWarriorWeaponBase>> CharacterCarriedWeaponMap;
};
