// StaminaComponent.h
// Auto-generated stamina component for player sprinting mechanics.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaminaComponent.generated.h"

class APlayerCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEADWOODSTAND_API UStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UStaminaComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	// Maximum stamina available
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float MaxStamina = 100.f;

	// Current stamina (runtime)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	float CurrentStamina = 100.f;

	// How fast stamina drains while sprinting (units per second)
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float DrainRate = 20.f;

	// How fast stamina recovers when not sprinting (units per second)
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float RecoveryRate = 15.f;

	// Delay after stopping sprinting before recovery starts (seconds)
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float RecoveryDelay = 1.5f;

private:
	// Internal timer counting seconds since last drain
	float RecoveryTimer = 0.f;
};

