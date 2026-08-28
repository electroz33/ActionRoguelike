// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RougeActionSystemComponent.generated.h"

USTRUCT(BlueprintType)
struct FRougeAttributeSet
{
	GENERATED_BODY()
	
	FRougeAttributeSet(): 
		Health(100.0f),
		MaxHealth(100.0f) {}
	
	UPROPERTY(BlueprintReadOnly)
	float Health;
	
	UPROPERTY(BlueprintReadOnly)
	float MaxHealth;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float,  NewHealth, float, OldHealth);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONROGUELIKE_API URougeActionSystemComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadOnly, Category="Attributes")
	FRougeAttributeSet Attributes;
	
	
public:
	URougeActionSystemComponent();

	void ApplyHealthChange(float InValueChange);
	
	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool IsFullHealth() const;
};
