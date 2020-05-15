// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
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



void UTankAimComponent::setBarrelRef(UStaticMeshComponent* SetTheBarrel) {

	Barrel = SetTheBarrel;
	

}


// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


//Aim at event
void UTankAimComponent::AimAt(FVector OutHitLoc, float LaunchSpied) {


	if (!Barrel) { 
		return;
	}



	//The toss velocity
	FVector OutLaunchVelocity(0);
	FVector StartLoc = Barrel->GetSocketLocation(FName("Projectile"));
	
	//auto tankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT(" %s aiming at %s from %s%"), *tankName, *OutHitLoc.ToString(),*BarrelLocation);




	//Calculate the OutLaunchVelocity

	if (UGameplayStatics::SuggestProjectileVelocity(this,OutLaunchVelocity,StartLoc,OutHitLoc,LaunchSpied
		,false,0,0, ESuggestProjVelocityTraceOption::DoNotTrace)) {


		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%sAiming at %s"), *TankName,*AimDirection.ToString());
		
	}
	else {

	}
	
	
}
