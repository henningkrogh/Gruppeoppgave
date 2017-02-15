// Fill out your copyright notice in the Description page of Project Settings.

#include "Uke4.h"
#include "MyPawn.h"
#include "Bullet.h"
#include "Enemy.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Dummy root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create visible component
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	// Attach visible component to root
	OurVisibleComponent->SetupAttachment(RootComponent);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayerCollisionBox"));
	CollisionBox->bGenerateOverlapEvents = true;
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMyPawn::OnOverlap);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->SetViewTarget(PlayerCamera);
	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveX", this, &AMyPawn::MoveXAxis);
	InputComponent->BindAxis("MoveY", this, &AMyPawn::MoveYAxis);

	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPawn::Shoot);

}

void AMyPawn::MoveXAxis(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 400.f;
}

void AMyPawn::MoveYAxis(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 400.f;
}

void AMyPawn::Shoot()
{
	UWorld* World = GetWorld();

	if (World && Ammo > 0)
	{
		FVector Location = GetActorLocation() + FVector(30.f, 0.f, 15.f);


		World->SpawnActor<ABullet>(BulletBlueprint, Location, FRotator::ZeroRotator);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShootFX, GetTransform(), true);
		UGameplayStatics::PlaySound2D(GetWorld(), ShootSound, 1.f, 1.f, 0.f);

		Ammo--;

		// UE_LOG(LogTemp, Warning, TEXT("Shoooooooot"))
	}
	else
	{
		UGameplayStatics::PlaySound2D(GetWorld(), NoAmmoSound, 1.f, 1.f, 0.f);
		return;
	}
}

void AMyPawn::SetScore()
{
	PlayerScore += 10;
	if (PlayerScore % 40 == 0)
	{
		Ammo += 5;
	}
}


void AMyPawn::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{

	if (OtherActor->IsA(AEnemy::StaticClass()))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathFX, GetTransform(), true);
		UGameplayStatics::PlaySound2D(GetWorld(), DeathSound, 1.f, 1.f, 0.f);

		Destroy();

	}
}
