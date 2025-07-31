// ChenGangQiang All rights Reserved.


#include "Items/Weapons/WarriorWeaponBase.h"
#include "Components/BoxComponent.h"

#include "WarriorDebugHelper.h"
// Sets default values
AWarriorWeaponBase::AWarriorWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionBeginOverlap);
	WeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionEndOverlap);

}

void AWarriorWeaponBase::OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();
	checkf(WeaponOwningPawn, TEXT("Forgot to assign an instiagtor as the owning pawn for the weapon: %s"), *GetName());

	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (HitPawn != WeaponOwningPawn)
		{
			OnWeaponHitTarget.ExecuteIfBound(OtherActor);
		}
		//
	}
}

void AWarriorWeaponBase::OnCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APawn* WeaponOwningPawn = GetInstigator<APawn>();
	checkf(WeaponOwningPawn, TEXT("Forgot to assign an instiagtor as the owning pawn for the weapon: %s"), *GetName());

	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (HitPawn != WeaponOwningPawn)
		{
			OnWeaponPulledFromTarget.ExecuteIfBound(OtherActor);
		}
		//
	}
}

