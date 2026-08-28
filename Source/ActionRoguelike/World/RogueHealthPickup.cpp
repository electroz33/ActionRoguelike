// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueHealthPickup.h"
#include "ActionSystem/RougeActionSystemComponent.h"

ARogueHealthPickup::ARogueHealthPickup()
{
	
}

void ARogueHealthPickup::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ARogueHealthPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	URougeActionSystemComponent* AttributeComp = OtherActor->FindComponentByClass<URougeActionSystemComponent>();
	if (ensure(AttributeComp != nullptr) && !AttributeComp->IsFullHealth())
	{
		Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex,bFromSweep, SweepResult);
		AttributeComp->ApplyHealthChange(HealAmount);
		Destroy();
	}
}



