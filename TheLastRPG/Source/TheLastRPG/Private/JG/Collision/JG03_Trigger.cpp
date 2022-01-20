// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG03_Trigger.h"
#include "JG/JG_Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"


// Ctrl+tap = 창바꾸기
// Ctrl+k+o = 헤더 cpp 왔다갔다
// Ctrl + 화살표 = 단어단위 왔다갔다
// Sets default values
AJG03_Trigger::AJG03_Trigger()
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
void AJG03_Trigger::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AJG03_Trigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AJG03_Trigger::ActorEndOverlap);

}


void AJG03_Trigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxLightBeginOverlap.IsBound()) 
		OnBoxLightBeginOverlap.Execute(); 

	if (OnBoxLightRandomBeginOverlap.IsBound())
	{
		FLinearColor color;
		color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.A = 1.0f;

		FString str = OnBoxLightRandomBeginOverlap.Execute(color);
		JG_Log::Log(str);
	}
}

void AJG03_Trigger::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxLightEndOverlap.IsBound()) 
		OnBoxLightEndOverlap.Execute(); 
}