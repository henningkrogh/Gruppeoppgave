// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class UKE4_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemy> EnemyBlueprint;
	
	void EnemySpawnTimer(float &SpawnTimer, float &Timer);
	void SpawnEnemies();
	float SpawnTimer = 25.f;
	float Timer = 25.f;

	// Prøver å prate med AEnemy klassen for å endre farten ved hver wave, men funker dårlig..
	AEnemy *CurrentClass;

	
};
