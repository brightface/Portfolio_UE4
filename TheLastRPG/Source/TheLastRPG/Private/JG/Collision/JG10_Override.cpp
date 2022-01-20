// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG10_Override.h"
#include "JG/JG_Global.h"
#include "JG/JG_Player.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AJG10_Override::AJG10_Override()
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
void AJG10_Override::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AJG10_Override::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AJG10_Override::ActorEndOverlap);
}

void AJG10_Override::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangeColorRed();
}

void AJG10_Override::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangeColorWhite();
}

void AJG10_Override::ChangeColorWhite_Implementation()
{
	AJG_Player* player = Cast<AJG_Player>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->ChangeColor(FLinearColor(0, 0, 1));
}