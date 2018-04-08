// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) 
	{
		 return nullptr;
	}else{ return Cast<ATank>(PlayerTank); }
}

void ATankAIController::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AI controller is here!"));

	auto PlayerPawn = GetPlayerTank();

	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI sees player tank: %s"), *(PlayerPawn->GetName()));
	}
}
