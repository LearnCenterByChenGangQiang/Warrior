// ChenGangQiang All rights Reserved.


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/WarriorHeroWeapon.h"

#include "WarriorDebugHelper.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" hit target: ") + HitActor->GetActorNameOrLabel(), FColor::Green);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* PulledActor)
{
	Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT("  's Weapon pulled withn ") + PulledActor->GetActorNameOrLabel(), FColor::Red);
}
