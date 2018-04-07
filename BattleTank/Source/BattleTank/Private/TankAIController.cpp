// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AI controller is here!"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI is controling: %s"), *(ControlledTank->GetName()));
	}
}
