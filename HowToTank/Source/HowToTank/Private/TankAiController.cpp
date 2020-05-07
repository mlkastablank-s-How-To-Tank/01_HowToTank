// Fill out your copyright notice in the Description page of Project Settings.

#include "HowToTank.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay(){

	Super::BeginPlay();


	//Defines the possessed tank
	//auto PossessedTank = GetControlledTank();

	auto PlayerTank = GetPlayerTank();


	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Cant find player tanky tank tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found the uber possesssed player: %s"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAiController::GetControlledTank() const {


	//Returns the playere controlled pawn
	return Cast<ATank>(GetPawn());	


	
}

ATank* ATankAiController::GetPlayerTank() const {


	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) {
		return nullptr;
	}

	return Cast<ATank>(PlayerPawn);



}
