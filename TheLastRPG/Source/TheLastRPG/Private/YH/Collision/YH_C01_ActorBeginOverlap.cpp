#include "YH/Collision/YH_C01_ActorBeginOverlap.h"
#include "YH/Global_YH.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"


AYH_C01_ActorBeginOverlap::AYH_C01_ActorBeginOverlap()
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
void AYH_C01_ActorBeginOverlap::BeginPlay()
{
	Super::BeginPlay();
	//액터로 부터상속받은애는 액터비긴오버랩이 있다. 델리게이트, 이벤트 동일한개념.
	OnActorBeginOverlap.AddDynamic(this, &AYH_C01_ActorBeginOverlap::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AYH_C01_ActorBeginOverlap::ActorEndOverlap);
	
}

void AYH_C01_ActorBeginOverlap::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	FString str = "";
	str.Append("C++ Actor Begin Overalp : ");
	str.Append(OtherActor->GetName());

	YH_CLog::Log(str);
}

void AYH_C01_ActorBeginOverlap::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
}


