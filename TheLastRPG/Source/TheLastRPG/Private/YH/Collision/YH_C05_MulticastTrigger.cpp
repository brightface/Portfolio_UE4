#include "YH/Collision/YH_C05_MulticastTrigger.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "YH/Global_YH.h"

// Sets default values
AYH_C05_MulticastTrigger::AYH_C05_MulticastTrigger()
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

void AYH_C05_MulticastTrigger::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AYH_C05_MulticastTrigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AYH_C05_MulticastTrigger::ActorEndOverlap);
}

void AYH_C05_MulticastTrigger::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OnMultiLightBeginOverlap.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);

		FLinearColor color;
		color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
		color.A = 1.0f;

		OnMultiLightBeginOverlap.Broadcast(index, color);
	}
}

void AYH_C05_MulticastTrigger::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{

}



