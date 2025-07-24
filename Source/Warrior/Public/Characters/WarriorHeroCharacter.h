// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;
class UHeroCombatComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorHeroCharacter();
protected:
	//~ Begin APawn interface
	/** 控制器接管角色时调用 */
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn interface

	/** 初始化输入组件绑定（使用 Enhanced Input） */
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	virtual void BeginPlay() override;

private:
#pragma region Components
	/** 摄像机弹簧臂，跟随角色移动 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	/** 摄像机组件，绑定在弹簧臂上 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	/** 战斗组件，处理角色的战斗逻辑 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;
#pragma endregion

#pragma region Input
	/** 输入配置资源（数据资产） */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	/** 输入响应：角色移动 */
	void Input_Move(const FInputActionValue& InputActionValue);

	/** 输入响应：角色视角控制 */
	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion

public:
	UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
