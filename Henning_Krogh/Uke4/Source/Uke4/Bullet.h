// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class UKE4_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector NewLocation;

	UPROPERTY(VisibleAnywhere)
	float Speed = 600.0f;
	float DespawnTime = 2.0f;

	UShapeComponent* CollisionSphere;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
		UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult &SweepResult);

	// VFX
	UPROPERTY(EditAnywhere)
		UParticleSystem* ExplotionFX;

	// Sound
	UPROPERTY(EditAnywhere)
		USoundBase* KillSound;

	int PlayerScore = 0;
	
};
