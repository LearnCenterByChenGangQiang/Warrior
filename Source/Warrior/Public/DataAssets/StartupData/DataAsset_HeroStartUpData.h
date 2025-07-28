// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartUpDataBase.h"
#include "WarriorTypes/WarriorStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"



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
