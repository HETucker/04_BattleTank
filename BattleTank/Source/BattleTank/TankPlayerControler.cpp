// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerControler.h"
#include "BattleTank.h"


ATank * ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

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
