// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */

UCLASS(meta = (BlueprintSpawnableComponent))//So this component will show up as a component on BP
class HOWTOTANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Elevation(float degreesPerSec);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSec = 25; //Default

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationinDegrees = 35; //Default


	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationinDegrees = 0; //Default
	
};
