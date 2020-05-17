// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class HOWTOTANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:

	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;

	ATank* GetPlayerTank() const;



	virtual void Tick(float DeltaTime) override;



};
