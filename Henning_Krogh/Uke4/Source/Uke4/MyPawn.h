// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class UKE4_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	void MoveXAxis(float AxisValue);
	void MoveYAxis(float AxisValue);

	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	int Ammo = 50;

	void SetScore();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	int PlayerScore = 0;

	FVector CurrentVelocity;
	bool Died = false;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ABullet> BulletBlueprint;


	UPROPERTY(EditAnywhere)
		AActor* PlayerCamera = nullptr;

	UPROPERTY(EditAnywhere)
	UShapeComponent* CollisionBox;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);

	// VFX
	UPROPERTY(EditAnywhere)
		UParticleSystem* DeathFX;
	UPROPERTY(EditAnyWhere)
		UParticleSystem* ShootFX;

	// Sound
	UPROPERTY(EditAnywhere)
		USoundBase* ShootSound;
	UPROPERTY(EditAnywhere)
		USoundBase* DeathSound;
	UPROPERTY(EditAnywhere)
		USoundBase* NoAmmoSound;
	
};
