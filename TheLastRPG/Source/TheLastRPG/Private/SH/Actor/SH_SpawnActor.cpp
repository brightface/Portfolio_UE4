// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/Actor/SH_SpawnActor.h"
#include "SH/Global_SH.h" // = "../Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"


// Sets default values
ASH_SpawnActor::ASH_SpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	/*ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/SungHoon/Meshes/SH_Cube.SH_Cube'");

	if (mesh.Succeeded())
	{
		Mesh->SetStaticMesh(mesh.Object);
	}*/

	UStaticMesh* mesh;
	SH_CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/SungHoon/Meshes/SH_Cube.SH_Cube'");
	Mesh->SetStaticMesh(mesh);
}

// Called when the game starts or when spawned
void ASH_SpawnActor::BeginPlay()
{
	Super::BeginPlay();

	// MaterialInstanceConstant'/Game/SungHoon/Materials/M_Mesh_Inst.M_Mesh_Inst'
	// UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), NULL, L"MaterialInstanceConstant'/Game/SungHoon/Materials/M_Mesh_Inst.M_Mesh_Inst'");
	//UMaterialInstanceConstant* material = Cast<UMaterialInstanceConstant>(obj);

	UMaterialInstanceConstant* material;
	SH_CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/SungHoon/Materials/M_Mesh_Inst.M_Mesh_Inst'");

	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material); // 0번째 인덱스에 우리가 만든 머티리얼을 할당한다.

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.0f, true);
}

void ASH_SpawnActor::ChangeColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.A = 1.0f;
	
	Material->SetVectorParameterValue("Color", color);
}