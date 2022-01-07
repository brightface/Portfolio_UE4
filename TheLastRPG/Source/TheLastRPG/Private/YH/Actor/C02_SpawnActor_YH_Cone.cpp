// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/Actor/C02_SpawnActor_YH_Cone.h"
#include "YH/Global_YH.h"

AC02_SpawnActor_YH_Cone::AC02_SpawnActor_YH_Cone()
{
	UStaticMesh* mesh;
	CHelpers_YH::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/YongHwan/Meshes/YH_Cone.YH_Cone'");
	Mesh->SetStaticMesh(mesh);
}