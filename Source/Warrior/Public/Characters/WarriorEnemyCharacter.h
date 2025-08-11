// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;
class UEnemyUIComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorEnemyCharacter();

	//~ Begin IPawnComboInterface interface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnComboInterface interface

	//~ Begin UPawnUIComponent interface
	virtual UPawnUIComponent* GetPawnUIComponent() const override;
	//~ End UPawnUIComponent interface

protected:
	//~ Begin APawn interface
	/** 控制器接管角色时调用 */
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	UEnemyUIComponent* EnemyUIComponent;

private:
	void InitEnemyStartUpData();

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent;}
};
