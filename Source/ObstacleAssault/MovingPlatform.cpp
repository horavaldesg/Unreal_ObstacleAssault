// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPos = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotatePlatform(DeltaTime);
	EndReached() ? ResetPlatform() : MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentPos = GetActorLocation();

	CurrentPos += PlatformVel * DeltaTime;

	SetActorLocation(CurrentPos);
}

bool AMovingPlatform::EndReached() const
{
	return DistanceMoved() > MaxDistance;
}

float AMovingPlatform::DistanceMoved() const
{
	return  FVector::Dist(StartPos, GetActorLocation());
}

void AMovingPlatform::ResetPlatform()
{
	const FVector MoveDir = PlatformVel.GetSafeNormal();
	StartPos = StartPos + MoveDir * MaxDistance;
	SetActorLocation(StartPos);
	PlatformVel = -PlatformVel;
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(PlatformRot * DeltaTime);
}

