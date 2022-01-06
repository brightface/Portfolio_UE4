// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/Actor/SH_SpawnActor_Sphere.h"
#include "SH/Global.h"


ASH_SpawnActor_Sphere::ASH_SpawnActor_Sphere()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/SungHoon/Meshes/SH_Sphere.SH_Sphere'");
	Mesh->SetStaticMesh(mesh);
}