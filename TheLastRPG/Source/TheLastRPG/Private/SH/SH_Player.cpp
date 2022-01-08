// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/SH_Player.h"
#include "SH/SH_Global.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h" // for GetCapsuleComponent

// Sets default values
ASH_Player::ASH_Player()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//SpringArm->SetupAttachment(GetCapsuleComponent());

	//Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	//Camera->SetupAttachment(SpringArm);

	SH_CHelpers::CreateComponent<USpringArmComponent>(this, &SpringArm, "SpringArm", GetCapsuleComponent());
	SH_CHelpers::CreateComponent<UCameraComponent>(this, &Camera, "Camera", SpringArm);

	bUseControllerRotationYaw = false; // 
	GetCharacterMovement()->bOrientRotationToMovement = true; // 이동하는 방향으로 회전가능
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	USkeletalMesh* mesh;
	SH_CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin_Female.SK_Mannequin_Female'");
	GetMesh()->SetSkeletalMesh(mesh);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->bDoCollisionTest = false; // 카메라와 물체 사이의 충돌체크 하겠냐는것. 카메라가 뒤집어질 수 있음. 끔.
	SpringArm->bUsePawnControlRotation = true; // 컨트롤러에 따라 폰이 움직여야 하기 떄문에 켜준다.

}

// Called when Sthe game starts or when spawned
void ASH_Player::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASH_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASH_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASH_Player::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASH_Player::OnMoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASH_Player::OnHorizontalLook);
	PlayerInputComponent->BindAxis("LookUp", this, &ASH_Player::OnVerticalLook);

}

void ASH_Player::OnMoveForward(float Axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ASH_Player::OnMoveRight(float Axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ASH_Player::OnHorizontalLook(float Axis)
{
	// 좌우
	AddControllerYawInput(Axis);
}

void ASH_Player::OnVerticalLook(float Axis)
{
	// 위아래
	AddControllerPitchInput(Axis);
}