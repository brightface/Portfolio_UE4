// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/C02_SpawnActor_YH.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "YH/Global_YH.h"
// Sets default values
AC02_SpawnActor_YH::AC02_SpawnActor_YH()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	/*ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/YongHwan/Meshes/YH_Cone.YH_Cone'");
	if (mesh.Succeeded())
		Mesh->SetStaticMesh(mesh.Object);*/
	
	UStaticMesh* mesh;
	CHelpers_YH::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/YongHwan/Meshes/YH_Cube.YH_Cube'");
	Mesh->SetStaticMesh(mesh);
	
}

// Called when the game starts or when spawned
void AC02_SpawnActor_YH::BeginPlay()
{
	Super::BeginPlay();
	UMaterialInstanceConstant* material;
	CHelpers_YH::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/M_Mesh_Inst.M_Mesh_Inst'");

	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.0f, true);
}

void AC02_SpawnActor_YH::ChangeColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.A = 1.0f;

	Material->SetVectorParameterValue("Color", color);
}


