// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"


//Forward Decleration
class UTankBarrel;



//Holds para for barrel properties ...oh and elevate the method

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOWTOTANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

	
protected:


public:	

	// Sets default values for this component's properties
	UTankAimComponent();

	void setBarrelRef(UTankBarrel * SetTheBarrel);

	
	//TODO add SetTurretRef
	//void SetTurretRef(UStaticMeshComponent* SetTheTurret);

	

	void AimAt(FVector OutHitLoc, float LaunchSpeeeeed
	);

	

private:

	//Static mesh for Mull's tank

	//Static Mesh for default tanks
	void MoveBarrelTo(FVector AimDir);
	UTankBarrel* Barrel = nullptr;
	UStaticMeshComponent* Turret = nullptr;
};
