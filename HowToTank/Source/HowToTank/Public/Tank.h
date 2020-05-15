// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class HOWTOTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLoc);

	
	UFUNCTION(BlueprintCallable, Category = Setup)//call from BP
	void setBarrelRef(UStaticMeshComponent* SetToBarrel);
	


protected:

	UTankAimComponent* TankAimComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeeeed = 100000; //TODO find sensible default

};
