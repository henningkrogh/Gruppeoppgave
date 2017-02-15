// Fill out your copyright notice in the Description page of Project Settings.

#include "Uke4.h"
#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	NewLocation = GetActorLocation();
	// MoveTimer += DeltaTime;

	SetSpeed(-70.f);

	DeltaWidth = (FMath::Cos(YTimer + DeltaTime) - FMath::Cos(YTimer));
	NewLocation.Y += (DeltaWidth * 50.f);
	NewLocation.X += (Speed * DeltaTime);
	YTimer += DeltaTime;
	SetActorLocation(NewLocation, false);

	// Trodde dette skulle fungere, men alt står stille hvis jeg prøver.
	//if (MoveTimer >= 0)
	//{

	//switch (MoveTimer)
	//	{
	//	case 1:
	//		NewLocation.X += (Speed * DeltaTime);
	//		SetActorLocation(NewLocation, false);
	//	case 5:
	//		NewLocation.X += (Speed * DeltaTime) * 0.f;
	//		NewLocation.Y += (Speed * DeltaTime);
	//		SetActorLocation(NewLocation, false);
	//	case 9:
	//		NewLocation.X += (Speed * DeltaTime);
	//		NewLocation.Y += (Speed * DeltaTime) * 0.f;
	//		SetActorLocation(NewLocation, false);
	//	case 13:
	//		NewLocation.X += (Speed * DeltaTime) * 0.f;
	//		NewLocation.Y -= (Speed * DeltaTime);
	//		SetActorLocation(NewLocation, false);
	//	case 17:
	//		NewLocation.X += (Speed * DeltaTime);
	//		NewLocation.Y += (Speed * DeltaTime) * 0.f;
	//		SetActorLocation(NewLocation, false);
	//	default:
	//		break;
	//	}
	//}
	//

	//if (MoveTimer >= 21)
	//{
	//	MoveTimer = 0;
	//}

	if (NewLocation.X <= -200.f)
	{
		Destroy();
	}

}


int AEnemy::GetSpeed()
{
	return Speed;
}

void AEnemy::SetSpeed(float InSpeed)
{
	Speed = InSpeed;
}