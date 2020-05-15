// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOWTOTANK_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Sets default values for this component's properties
	UTankAimComponent();

	void setBarrelRef(UStaticMeshComponent* SetTheBarrel);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector OutHitLoc, float LaunchSpeeeeed
	);

private:

	//Static mesh for Mull's tank

	//Static Mesh for default tanks
	UStaticMeshComponent* Barrel = nullptr;
};
