// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Ladder.generated.h"

UCLASS()
class TESTCPPPROJECT_API ALadder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALadder();

	UPROPERTY(EditAnywhere)
	float height = 100.0f;

	UPROPERTY(EditAnywhere)
	float width = 10.0f;

	UPROPERTY()
	USceneComponent* root;

	UPROPERTY()
	UBoxComponent* BoxCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
				FVector NormalImpulse, const FHitResult& Hit);

};
