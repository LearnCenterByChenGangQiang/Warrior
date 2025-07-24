// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorHeroCharacter;
class AWarriorHeroController;
class UHeroCombatComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	/** 获取当前激活该能力的英雄角色（AWarriorHeroCharacter）*/
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();

	/** 获取当前激活该能力的控制器（AWarriorHeroController）*/
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController*GetHeroControllerFromActorInfo();

	/** 获取英雄角色身上的战斗组件 */
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	/** 缓存的英雄角色指针，避免每次调用都执行 Cast */
	TWeakObjectPtr<AWarriorHeroCharacter> CachedWarriorHeroCharacter;

	/** 缓存的控制器指针，避免每次调用都执行 Cast */
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
};
