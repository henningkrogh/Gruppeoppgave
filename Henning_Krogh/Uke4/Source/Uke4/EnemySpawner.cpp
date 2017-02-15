// Fill out your copyright notice in the Description page of Project Settings.

#include "Uke4.h"
#include "EnemySpawner.h"
#include "Enemy.h"


// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnEnemies();
	
}

// Called every frame
void AEnemySpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	SpawnTimer -= DeltaTime;

	EnemySpawnTimer(SpawnTimer, Timer);

}

void AEnemySpawner::EnemySpawnTimer(float &SpawnTimer, float &Timer)
{

	if (SpawnTimer <= 0)
	{
		SpawnEnemies();
		Timer -= 2.f;

		if (Timer < 10.f)
		{
			Timer = 10.f;
		}

		SpawnTimer = Timer;

	}
	
}

void AEnemySpawner::SpawnEnemies()
{
	UWorld* World = GetWorld();
	
	if (World)
	{
		for (int I = 1; I <= 5; I++)
		{
			{
				for (int J = 1; J <= 8; J++)
				{
					World->SpawnActor<AEnemy>(EnemyBlueprint, FVector(800.f + ((100.f) * I), (-680.f + (160.f) * J), 30.f), FRotator::ZeroRotator);
				}
			}
		}
		
	}
	//float NewSpeed = CurrentClass->GetSpeed() - 100.f;
	//CurrentClass->SetSpeed(NewSpeed);
}
