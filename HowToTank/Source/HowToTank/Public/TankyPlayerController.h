// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HOWTOTANK_API ATankyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:


	virtual void BeginPlay() override;
	//Let it tick
	virtual void Tick(float DeltaTime) override;


private:
	//Barrel tracking
	virtual void Aim();



	ATank* GetControlledTank() const;


	

	//Get the sight of the hit location, pass a reference to FVector

	bool GetSightHitLoc(FVector& OutHitLoc) const;

	bool GetLookVectorHitLoc(FVector WorldDir, FVector & Hitloc) const;

	bool GetLookDir(FVector2D ScreenLoc, FVector & WorldDir) const;


	UPROPERTY(EditAnywhere)
	//Default pos 
	float CrossHairXLoc = 0.5;

	UPROPERTY(EditAnywhere)
	//Accurate Y loc, dont @me
	float CrossHairYLoc = 0.333333;

	UPROPERTY(EditAnywhere)
		//10km
	float LineTraceRange = 1000000.0;

	
	
};
