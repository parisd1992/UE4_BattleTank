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
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}
