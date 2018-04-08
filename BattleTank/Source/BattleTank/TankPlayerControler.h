// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControler.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerControler : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:

	void AimTwardsCrosshairs();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333;


};
