// Fill out your copyright notice in the Description page of Project Settings.


#include "RoguePickUpActor.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

ARoguePickUpActor::ARoguePickUpActor()
{
	OverlapComponent->SetupAttachment(PickUpComponent);
	OverlapComponent->SetSphereRadius(50.0f);
	OverlapComponent->SetCollisionProfileName("Pickups");
	OverlapComponent->SetSphereRadius(128.0f);
	PickUpComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUp Comp"));
	PickUpComponent->SetCollisionProfileName("NoCollision");
	OverlapComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Comp"));
	
	RootComponent = OverlapComponent;
	PickUpComponent->SetupAttachment(OverlapComponent);
}

void ARoguePickUpActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &ARoguePickUpActor::OnOverlapBegin);
}

void ARoguePickUpActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                       const FHitResult& SweepResult)
{
	
}

