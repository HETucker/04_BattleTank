// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerControler.h"
#include "BattleTank.h"


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
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //Out Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
	//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
	}
}

ATank * ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerControler::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);

	return true;
}
