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

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
    {
        return;
    }
    
    UE_LOG(LogTemp, Log, TEXT("Aiming towards crosshair!"));
    
    //TODO: get world location if linetrace through crosshair
    //TODO: if it hits the landscape, tell controlled tank to aim at this point
}

