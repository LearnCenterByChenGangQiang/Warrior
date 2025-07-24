// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 将数据资产中定义的所有能力赋予指定的 AbilitySystemComponent */
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel = 1);
protected:
	/** 被赋予后立即激活的能力列表（如 OnGiven 策略的能力） */
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray< TSubclassOf<UWarriorGameplayAbility> > ActivateOnGivenAbilities;

	/** 被动/反应式能力（如监听事件、自动反击等） */
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray< TSubclassOf<UWarriorGameplayAbility> > ReactiveAbilities;

	/** 将指定能力列表赋予目标 ASC */
	void GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel);
};
