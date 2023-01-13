// Fill out your copyright notice in the Description page of Project Settings.


#include "Ladder.h"

// Sets default values
ALadder::ALadder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	root = CreateDefaultSubobject<USceneComponent>("Root");
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("Trigger");
	
	BoxCollision->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->SetRelativeLocation(FVector(0.0f, 0.0f, height * 0.5f));
	BoxCollision->SetBoxExtent(FVector(width, 0.5f, height));
}

// Called when the game starts or when spawned
void ALadder::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALadder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALadder::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Climbing Ladder"));
}

