// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG02_ComponentBeginOverlap.h"
#include "JG/JG_Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"
// Sets default values
AJG02_ComponentBeginOverlap::AJG02_ComponentBeginOverlap()
{
	JG_Helpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	JG_Helpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	JG_Helpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	JG_Helpers::CreateComponent<UPointLightComponent>(this, &PointLight, "PointLight", Scene);

	Box->SetRelativeScale3D(FVector(3)); // 각 벡터의 3배
	Box->bHiddenInGame = false;  // 생성자에 지역변수가 있으면 지역변수 사용해주는게 좋음

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	PointLight->SetLightColor(FLinearColor::Red);

}

// Called when the game starts or when spawned
void AJG02_ComponentBeginOverlap::BeginPlay()
{
	Super::BeginPlay();
	
	PointLight->SetVisibility(false);

	Box->OnComponentBeginOverlap.AddDynamic(this, &AJG02_ComponentBeginOverlap::ComponentBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &AJG02_ComponentBeginOverlap::ComponentEndOverlap);

}

void AJG02_ComponentBeginOverlap::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PointLight->SetVisibility(true);
}

void AJG02_ComponentBeginOverlap::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PointLight->SetVisibility(false);
}
