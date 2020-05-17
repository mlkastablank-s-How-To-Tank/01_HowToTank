// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "HowToTank.h"
#include "TankAimComponent.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTankAimComponent::setBarrelRef(UTankBarrel* SetTheBarrel) {

	Barrel = SetTheBarrel;
	

}



//Aim at event
void UTankAimComponent::AimAt(FVector OutHitLoc, float LaunchSpied) {


	if (!Barrel) { 
		return;
	}



	//The toss velocity (out parameter)
	FVector OutLaunchVelocity(0);
	FVector StartLoc = Barrel->GetSocketLocation(FName("Projectile"));



	//Aim Solution
	bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLoc, OutHitLoc, LaunchSpied
		, ESuggestProjVelocityTraceOption::DoNotTrace);
	//auto tankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT(" %s aiming at %s from %s%"), *tankName, *OutHitLoc.ToString(),*BarrelLocation);

	//Calculate the OutLaunchVelocity

	if (bAimSolution) {


		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%sAiming at %s"),*AimDirection.ToString());

		MoveBarrelTo(AimDirection);
		
	}
	else {

	}
	
	
}

void UTankAimComponent::MoveBarrelTo(FVector AimDir) {


	//Workout diff between current barrel and aim dir
	auto barrelRotation = Barrel->GetForwardVector().Rotation();
	auto aimRotater = AimDir.Rotation();
	auto deltaRotator = aimRotater - barrelRotation;
	UE_LOG(LogTemp, Warning, TEXT("aimRotater at %s"), *aimRotater.ToString());
	

	Barrel->Elevation(5); //TODO remove sshit
}
