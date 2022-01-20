// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Trace/JG01_Cylinder.h"
#include "JG/JG_Global.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AJG01_Cylinder::AJG01_Cylinder()
{
	JG_Helpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	JG_Helpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	JG_Helpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 140));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	UStaticMesh* mesh;
	JG_Helpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/JongGyun/Meshs/M_Cylinder.M_Cylinder'");

	Mesh->SetStaticMesh(mesh);
	Mesh->SetRelativeScale3D(FVector(1, 1, 2.5f));
}

// Called when the game starts or when spawned
void AJG01_Cylinder::BeginPlay()
{
	Super::BeginPlay();
	
}
