// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    auto controlledTank = GetControlledTank();
    if (controlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController controlled tank: %s"), *(controlledTank->GetName()));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController no controlled tank"));
    }
    
    auto playerTank = GetPlayerTank();
    if (playerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(playerTank->GetName()));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController did not find player tank"));
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn)
    {
        return nullptr;
    }
    
    return Cast<ATank>(PlayerPawn);
}
