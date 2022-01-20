// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/Collision/YH_C08_EventTrigger.h"
#include "YH/Global_YH.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AYH_C08_EventTrigger::AYH_C08_EventTrigger()
{
	CHelpers_YH::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers_YH::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers_YH::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

}

// Called when the game starts or when spawned
void AYH_C08_EventTrigger::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AYH_C08_EventTrigger::ActorBeginOverlap);
}

void AYH_C08_EventTrigger::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OnEventTrigger.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);

		OnEventTrigger.Broadcast(index);
	}
}


