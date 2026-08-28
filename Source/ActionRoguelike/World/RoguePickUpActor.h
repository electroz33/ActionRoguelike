// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoguePickUpActor.generated.h"


class USphereComponent;
class UStaticMeshComponent;
UCLASS()
class ACTIONROGUELIKE_API ARoguePickUpActor : public AActor
{
	GENERATED_BODY()

public:
	ARoguePickUpActor();
	
	virtual void PostInitializeComponents() override;
	
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
protected:
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<UStaticMeshComponent> PickUpComponent;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<USphereComponent> OverlapComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> PickUpSound;
	};
