// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto controlledTank = GetControlledTank();
    if (controlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController controlled tank: %s"), *(controlledTank->GetName()));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController no controlled tank"));
    }
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}