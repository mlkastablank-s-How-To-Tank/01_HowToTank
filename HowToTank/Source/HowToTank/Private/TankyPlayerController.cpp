// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
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

	FVector OutHitLoc; //out parameter

	if (GetSightHitLoc(OutHitLoc)) {

		
	
	//TODO Tell the tank to aim

		GetControlledTank() -> AimAt(OutHitLoc);

	}

	
}


//Get Hit Location of the line trace through the aim crosshairs, true if shit hits

bool ATankyPlayerController::GetSightHitLoc(FVector& OutHitLoc) const {


	//Pixel coordinates
	int32 viewPortSizeX, viewPortSizeY;

	GetViewportSize(viewPortSizeX, viewPortSizeY);

	FVector2D ScreenLoc(viewPortSizeX * CrossHairXLoc, viewPortSizeY * CrossHairYLoc);



	//DeProject the screen pos of the crosshair to a world direction


	//Unit Vector
	FVector WorldDir;
	
	if (GetLookDir(ScreenLoc, WorldDir)) {

		//trace along the look direction (like a invisible laser sight)
		GetLookVectorHitLoc(WorldDir, OutHitLoc);
	}
	


	return true;


}

bool ATankyPlayerController::GetLookVectorHitLoc(FVector WorldDir,FVector& OutHitLoc) const {


	FHitResult hitResult;
	auto startLoc = PlayerCameraManager->GetCameraLocation();
	auto endLoc = startLoc + (WorldDir * LineTraceRange);


	//LineTrace succeeds
	if (GetWorld()->LineTraceSingleByChannel(hitResult,startLoc,endLoc,ECollisionChannel::ECC_Visibility)) {

		//Set hit loc

		OutHitLoc = hitResult.Location;
		return true;
	}
	else {
		return false;
	}

}


//ScreenLoc = WorldLocation
bool ATankyPlayerController::GetLookDir(FVector2D ScreenLoc, FVector& WorldDir) const{


	FVector CameraWorldLoc; //will be deleted
	

	return DeprojectScreenPositionToWorld(ScreenLoc.X, ScreenLoc.Y, CameraWorldLoc, WorldDir);
	



}


