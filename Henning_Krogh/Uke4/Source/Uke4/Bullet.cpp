// Fill out your copyright notice in the Description page of Project Settings.

#include "Uke4.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MyPawn.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
	CollisionSphere->bGenerateOverlapEvents = true;
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);



}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	NewLocation = GetActorLocation();
	NewLocation.X += (Speed * DeltaTime);
	SetActorLocation(NewLocation, false);
	
	DespawnTime -= DeltaTime;

	if (DespawnTime <= 0 )
	{
		Destroy();
	}

}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{

	if (OtherActor->IsA(AEnemy::StaticClass()))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplotionFX, GetTransform(), true);
		UGameplayStatics::PlaySound2D(GetWorld(), KillSound, 1.f, 1.f, 0.f);


		AMyPawn* PawnRef = Cast<AMyPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());;
		if (PawnRef)
		{
			PawnRef->SetScore();
		}

		PlayerScore += 10;

		OtherActor->Destroy();
		Destroy();
	}
}


