// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class UKE4_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector NewLocation;
	float YTimer;
	float DeltaWidth;

	UPROPERTY(EditAnywhere)
	float Speed;
	float asdf;
	int MoveTimer = 0;

	int GetSpeed();
	void SetSpeed(float InSpeed);
	
};
