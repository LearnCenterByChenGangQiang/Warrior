// ChenGangQiang All rights Reserved.


#include "DataAssets/Input/DataAsset_InputConfig.h"

/**
 * 根据输入标签查找原生输入动作。
 *
 * 该函数仅在 NativeInputActions 列表中查找，不会查找 Ability 输入。
 *
 * @param InputTag 要查找的输入标签
 * @return 如果找到了有效的 UInputAction，则返回它；否则返回 nullptr
 */
UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FWarriorInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
