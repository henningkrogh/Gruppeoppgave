// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "Uke4GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UKE4_API AUke4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Constructor
	AUke4GameModeBase();

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemy> EnemyBlueprint;

	
	
};
