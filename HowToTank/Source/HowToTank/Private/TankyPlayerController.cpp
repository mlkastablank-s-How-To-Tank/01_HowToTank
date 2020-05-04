// Fill out your copyright notice in the Description page of Project Settings.

#include "HowToTank.h"
#include "TankyPlayerController.h"



void ATankyPlayerController::BeginPlay() {

	Super::BeginPlay();


	auto PossessedTank = GetControlledTank();

	if (!PossessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("No tank being possessed"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play being possessed: %s"), *(PossessedTank->GetName()));
	}


}


ATank* ATankyPlayerController::GetControlledTank() const {


	//Returns the playere controlled pawn
	return Cast<ATank>(GetPawn());
}
