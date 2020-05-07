// Fill out your copyright notice in the Description page of Project Settings.

#include "HowToTank.h"
#include "TankyPlayerController.h"



void ATankyPlayerController::BeginPlay() {

	Super::BeginPlay();


	//Defines the possessed tank
	auto PossessedTank = GetControlledTank();

	
	//You can read right?

	if (!PossessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("No tank being possessed"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play being possessed: %s"), *(PossessedTank->GetName()));
	}


}


void ATankyPlayerController::Tick(float DeltaTime) {

	Super::Tick( DeltaTime );

	
	Aim();

}



ATank* ATankyPlayerController::GetControlledTank() const {


	//Returns the playere controlled pawn
	return Cast<ATank>(GetPawn());
}



void ATankyPlayerController::Aim()  {

	if (!GetControlledTank()) {
		return;
	}

	FVector HitLoc;

	if (GetSightHitLoc(HitLoc)) {

		//UE_LOG(LogTemp, Warning, TEXT("HitLoc look direction: %s"), *HitLoc.ToString());
		
	//TODO Tell the tank to aim

	}

	
}


//Get Hit Location of the line trace through the aim crosshairs, true if shit hits

bool ATankyPlayerController::GetSightHitLoc(FVector& OutHitLoc) const{


	//For testing
	/*OutHitLoc = FVector(1.0);*/

	//Pixel coordinates
	int32 viewPortSizeX, viewPortSizeY;

	GetViewportSize(viewPortSizeX, viewPortSizeY);

	FVector2D ScreenLoc(viewPortSizeX * CrossHairXLoc, viewPortSizeY * CrossHairYLoc);
	
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLoc: %s"), *ScreenLoc.ToString());


	//De Project the screen pos of the crosshair to a world direction
	//trace along the look direction (like a invisible laser sight)


	return true;


}