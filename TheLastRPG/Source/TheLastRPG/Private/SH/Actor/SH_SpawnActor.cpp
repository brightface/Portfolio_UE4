// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/Actor/SH_SpawnActor.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ASH_SpawnActor::ASH_SpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/SungHoon/Meshes/SH_Cube.SH_Cube'");

	if (mesh.Succeeded())
	{
		Mesh->SetStaticMesh(mesh.Object);
	}
}

// Called when the game starts or when spawned
void ASH_SpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
}

