#include "YH/Collision/YH_C02_ComponentBeginOverlap.h"
#include "YH/Global_YH.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"

AYH_C02_ComponentBeginOverlap::AYH_C02_ComponentBeginOverlap()
{
	CHelpers_YH::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers_YH::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers_YH::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers_YH::CreateComponent<UPointLightComponent>(this, &PointLight, "PointLight", Scene);


	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;
	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	
}

void AYH_C02_ComponentBeginOverlap::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AYH_C02_ComponentBeginOverlap::ComponentBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &AYH_C02_ComponentBeginOverlap::ComponentEndOverlap);
}

void AYH_C02_ComponentBeginOverlap::ComponentBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

void AYH_C02_ComponentBeginOverlap::ComponentEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}


