// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG05_MulticastTrigger.h"
#include "JG/JG_Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
// Sets default values
AJG05_MulticastTrigger::AJG05_MulticastTrigger()
{
	JG_Helpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	JG_Helpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	JG_Helpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

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
void AJG05_MulticastTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AJG05_MulticastTrigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AJG05_MulticastTrigger::ActorEndOverlap);

}

void AJG05_MulticastTrigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnMultiLightBeginOverlap.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);

		FLinearColor color;
		color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.A = 1.0f;

		OnMultiLightBeginOverlap.Broadcast(index, color); // execute(½Ì±Û) vs Broadcast(¸ÖÆ¼)
	}
}

void AJG05_MulticastTrigger::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{

}