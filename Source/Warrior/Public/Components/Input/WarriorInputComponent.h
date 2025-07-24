// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	/**
	 * 绑定原生输入动作（非能力），通过输入标签查找并绑定到指定回调。
	 * 
	 * @tparam UserObject        回调函数的对象类型
	 * @tparam CallbackFunc      回调函数类型
	 * @param InInputConfig      输入配置数据（DataAsset）
	 * @param InInputTag         要绑定的输入标签（如 InputTag.Move）
	 * @param TriggerEvent       输入触发时机（Pressed、Released、Triggered 等）
	 * @param ContextObject      执行回调的对象
	 * @param Func               回调函数指针
	 */
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	/**
	 * 批量绑定所有“能力输入”的动作，包括按下和释放的处理函数。
	 * 
	 * @tparam UserObject           回调执行对象类型
	 * @tparam CallbackFunc         回调函数类型（要求按下和释放函数签名相同）
	 * @param InInputConfig         输入配置数据（DataAsset）
	 * @param ContextObject         执行回调的对象（一般为角色）
	 * @param InputPressedFunc      能力按下时执行的函数
	 * @param InputReleaseFunc      能力释放时执行的函数
	 */
	template<class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputReleaseFunc);

};


/**
 * 绑定一个原生输入动作（例如 Move、Look、Jump）到回调函数。
 * 
 * 根据输入标签从配置中查找输入动作，并在指定触发事件时调用回调。
 */
template <class UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	// 校验输入配置不为空
	checkf(InInputConfig, TEXT("输入配置数据资源为空，无法继续绑定。Input config data asset is null, can not proceed with binding"));

	// 根据输入标签查找对应的 InputAction
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		// 将动作与回调绑定
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}


/**
 * 绑定所有 AbilityInputActions 到回调函数（支持按下与释放事件）。
 * 
 * 每个 Ability 都定义了一个标签与 InputAction，通过循环批量绑定。
 */
template <class UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig,
	UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputReleaseFunc)
{
	// 校验输入配置有效
	checkf(InInputConfig, TEXT("输入配置数据资源为空，无法继续绑定。Input config data asset is null, can not proceed with binding"));

	// 遍历所有定义的能力输入动作
	for (const FWarriorInputActionConfig& AbilityInputActionConfig : InInputConfig->AbilityInputActions)
	{
		// 跳过无效配置（InputTag 无效或 InputAction 为空）
		if (!AbilityInputActionConfig.IsValid()) continue;

		// 绑定按下事件（Started）
		BindAction(AbilityInputActionConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, AbilityInputActionConfig.InputTag);
		// 绑定释放事件（Completed）
		BindAction(AbilityInputActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleaseFunc, AbilityInputActionConfig.InputTag);
	}
}
