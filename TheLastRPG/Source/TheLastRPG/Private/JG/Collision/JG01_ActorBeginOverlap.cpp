// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG01_ActorBeginOverlap.h"
#include "JG/JG_Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AJG01_ActorBeginOverlap::AJG01_ActorBeginOverlap()
{

	JG_Helpers::CreateComponent<USceneComponent>(this, &Scene, "Scene"); 
	JG_Helpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	JG_Helpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Box->SetRelativeScale3D(FVector(3)); // 각 벡터의 3배
	Box->bHiddenInGame = false;  // 생성자에 지역변수가 있으면 지역변수 사용해주는게 좋음

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName()); 
}

// Called when the game starts or when spawned
void AJG01_ActorBeginOverlap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AJG01_ActorBeginOverlap::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AJG01_ActorBeginOverlap::ActorEndOverlap);
}


void AJG01_ActorBeginOverlap::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	FString str = "";
	str.Append("C++ Actor Begin Overlap : ");
	str.Append(OtherActor->GetName());

	JG_Log::Log(str);
}

void AJG01_ActorBeginOverlap::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	FString str = "";
	str.Append("C++ Actor End Overlap : ");
	str.Append(OtherActor->GetName());

	JG_Log::Log(str);
}