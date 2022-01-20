#include "YH/Trace/YH_C01_Cylinder.h"
#include "YH/Global_YH.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"

AYH_C01_Cylinder::AYH_C01_Cylinder()
{
	CHelpers_YH::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers_YH::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers_YH::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 140));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());


	UStaticMesh* mesh;
	//StaticMesh'/Game/YongHwan/Meshes/YH_Cylinder.YH_Cylinder'
	CHelpers_YH::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/YongHwan/Meshes/YH_Cylinder.YH_Cylinder'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetRelativeScale3D(FVector(1, 1, 2.5f));

}


void AYH_C01_Cylinder::BeginPlay()
{
	Super::BeginPlay();
	
}


