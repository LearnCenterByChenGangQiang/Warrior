// ChenGangQiang All rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()
protected:
	/**
	 * 获取该组件所属的 Pawn（模板版，可指定返回类型）。
	 * 
	 * @tparam T 想要返回的 Pawn 类型，必须是 APawn 的子类。
	 * @return  转换后的 Pawn 指针，如果类型不匹配会崩溃。
	 */
	template <class T>
	T* GetOwningPawn() const
	{
		// static_assert 是编译时检查，确保你传的 T 是 APawn 的子类，否则编译报错
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be a subclass of APawn");
		return CastChecked<T>(GetOwner());
	}

	/**
	 * 获取该组件所属的 Pawn（默认返回 APawn 指针）。
	 * 
	 * 等价于 GetOwningPawn<APawn>()，简化调用。
	 */
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	/**
	 * 获取 Pawn 的控制器（模板版，可指定返回类型）。
	 * 
	 * @tparam T 想要返回的控制器类型，必须是 AController 的子类。
	 * @return 转换后的控制器指针，如果类型不匹配会崩溃。
	 */
	template <class T>
	T* GetOwningController() const
	{
		// 编译期检查：确保 T 是 AController 或其子类
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T must be a subclass of AController");
		// 通过 Pawn 获取控制器，并转换为指定类型
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
