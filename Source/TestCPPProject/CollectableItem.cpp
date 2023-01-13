// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableItem.h"
#include "CollectorState.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACollectableItem::ACollectableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	defaultSceneRoot = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");
	SetRootComponent(defaultSceneRoot);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mesh->AttachToComponent(defaultSceneRoot, FAttachmentTransformRules::KeepRelativeTransform);
	mesh->SetCollisionProfileName("Collectible", true);

	collectTrigger = CreateDefaultSubobject<ATriggerBox>("CollectTrigger");
}

// Called when the game starts or when spawned
void ACollectableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACollectorState* collector = static_cast<ACollectorState*>(UGameplayStatics::GetPlayerState(GetWorld(), 0));

	if (collector != NULL)
	{
		collector->Score += itemValue;
		Destroy();
	}
}

