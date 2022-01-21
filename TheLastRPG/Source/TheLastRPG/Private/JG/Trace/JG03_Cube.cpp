// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Trace/JG03_Cube.h"
#include "JG/JG_Global.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AJG03_Cube::AJG03_Cube()
{
	JG_Helpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	UStaticMesh* mesh;
	JG_Helpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/JongGyun/Meshs/M_Cube.M_Cube'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

}

// Called when the game starts or when spawned
void AJG03_Cube::BeginPlay()
{
	Super::BeginPlay();
	
}

