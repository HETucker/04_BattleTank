// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerControler.h"
#include "Public/Tank.h"

void ATankPlayerControler::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Playercontroler is here!"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controling: %s"),*(ControlledTank->GetName()));
	}
}

void ATankPlayerControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTwardsCrosshairs();
}

void ATankPlayerControler::AimTwardsCrosshairs()
{
	float LaunchSpeed = 10000;
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //Out Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

ATank * ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerControler::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *LookDirection.ToString());
	}


	return true;
}

bool ATankPlayerControler::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
	

}

bool ATankPlayerControler::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) 
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
