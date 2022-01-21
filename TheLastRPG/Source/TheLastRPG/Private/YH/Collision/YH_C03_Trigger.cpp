#include "YH/Global_YH.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "YH/Collision/YH_C03_Trigger.h"

AYH_C03_Trigger::AYH_C03_Trigger()
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
//박스 붙였다.
void AYH_C03_Trigger::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AYH_C03_Trigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AYH_C03_Trigger::ActorEndOverlap);

}

void AYH_C03_Trigger::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
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
		YH_CLog::Log(str);
	}
}

void AYH_C03_Trigger::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	if (OnBoxLightEndOverlap.IsBound())
		OnBoxLightEndOverlap.Execute();
}



