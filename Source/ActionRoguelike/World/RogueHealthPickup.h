// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoguePickUpActor.h"
#include "RogueHealthPickup.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ARogueHealthPickup : public ARoguePickUpActor
{
	GENERATED_BODY()

public:
	ARogueHealthPickup();
	
	virtual void PostInitializeComponents() override;
	
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult) override;
protected:

	UPROPERTY(EditDefaultsOnly, Category="Health")
	float HealAmount;
};
