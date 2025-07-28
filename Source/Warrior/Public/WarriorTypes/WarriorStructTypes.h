// ChenGangQiang All rights Reserved.

#pragma once
#include "WarriorStructTypes.generated.h"

class UWarriorHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponDta
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};
