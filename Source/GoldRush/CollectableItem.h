// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "CollectableItem.generated.h"

UCLASS(Abstract)
class GOLDRUSH_API ACollectableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableItem();

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* defaultSceneRoot;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* collectTrigger; // Trigger for collecting item

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* mesh; // Collectable mesh

	UPROPERTY(EditDefaultsOnly)
	int itemValue; // How much this item is worth when collected

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called when item has been collected
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
