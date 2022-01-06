// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/Actor/C02_SpawnActor_YH_Sphere.h"
#include "YH/Global_Yh.h"

AC02_SpawnActor_YH_Sphere::AC02_SpawnActor_YH_Sphere()
{
	UStaticMesh* mesh;
	CHelpers_YH::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/YongHwan/Meshes/YH_Sphere.YH_Sphere'");
	Mesh->SetStaticMesh(mesh);
}
