// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	void ResetPlatform();
	bool EndReached() const;
	float DistanceMoved() const;
	
	UPROPERTY(EditAnywhere)
	FVector StartPos;

	UPROPERTY(EditAnywhere)
	float MaxDistance = 500;
	
	
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVel= FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Rotating Platform")
	FRotator PlatformRot = FRotator(0,0,0);
};
