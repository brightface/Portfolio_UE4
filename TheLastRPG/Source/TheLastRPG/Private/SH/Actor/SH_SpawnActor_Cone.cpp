// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/Actor/SH_SpawnActor_Cone.h"
#include "SH/Global_SH.h"


ASH_SpawnActor_Cone::ASH_SpawnActor_Cone()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/SungHoon/Meshes/SH_Cone.SH_Cone'");
	Mesh->SetStaticMesh(mesh);
}