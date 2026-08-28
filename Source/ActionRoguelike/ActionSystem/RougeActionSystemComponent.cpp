// Fill out your copyright notice in the Description page of Project Settings.


#include "RougeActionSystemComponent.h"


URougeActionSystemComponent::URougeActionSystemComponent()
{
	
}

void URougeActionSystemComponent::ApplyHealthChange(float InValueChange)
{
	
	float Oldhealth = Attributes.Health;
	
	
	Attributes.MaxHealth = GetDefault<URougeActionSystemComponent>()->Attributes.Health;
	
	Attributes.Health = FMath::Clamp(Attributes.Health + InValueChange, 0.0f, Attributes.MaxHealth);
	
	if (!FMath::IsNearlyEqual(Attributes.Health, Oldhealth))
	{
		OnHealthChanged.Broadcast(Attributes.Health, Oldhealth);

	}
	
	
	UE_LOG(LogTemp, Log, TEXT("New Health: %f, Max Health: %f"), Attributes.Health, Attributes.MaxHealth);
}

bool URougeActionSystemComponent::IsFullHealth() const
{
	return FMath::IsNearlyEqual(Attributes.Health, Attributes.MaxHealth);
}
