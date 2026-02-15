#include "StaminaComponent.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter.h"

UStaminaComponent::UStaminaComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UStaminaComponent::BeginPlay()
{
	Super::BeginPlay();

	// Initialize current stamina to max at start
	CurrentStamina = MaxStamina;
}

void UStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Default: assume not sprinting
	bool bIsSprinting = false;

	if (APlayerCharacter* PC = Cast<APlayerCharacter>(GetOwner()))
	{
		bIsSprinting = PC->IsSprinting();
	}

	if (bIsSprinting)
	{
		CurrentStamina -= DrainRate * DeltaTime;
		RecoveryTimer = 0.f;
	}
	else
	{
		RecoveryTimer += DeltaTime;

		if (RecoveryTimer >= RecoveryDelay)
		{
			CurrentStamina += RecoveryRate * DeltaTime;
		}
	}

	CurrentStamina = FMath::Clamp(CurrentStamina, 0.f, MaxStamina);
}
