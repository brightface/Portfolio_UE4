// Fill out your copyright notice in the Description page of Project Settings.


#include "YH/CPlayer_YH.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "YH/Global_YH.h"

// Sets default values
ACPlayer_YH::ACPlayer_YH()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//SpringArm->SetupAttachment(GetCapsuleComponent());

	//Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	//Camera->SetupAttachment(SpringArm);


	CHelpers_YH::CreateComponent<USpringArmComponent>(this, &SpringArm, "SpringArm", GetCapsuleComponent());
	CHelpers_YH::CreateComponent<UCameraComponent>(this, &Camera, "Camera", SpringArm);


	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;

	USkeletalMesh* mesh;
	CHelpers_YH::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'");
	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	TSubclassOf<UAnimInstance> animInstance;
	CHelpers_YH::GetClass<UAnimInstance>(&animInstance, "Blueprint'/Game/YongHwan/BP/YH_BP_CAnimInstance.YH_BP_CAnimInstance_C'");
	GetMesh()->SetAnimInstanceClass(animInstance);

	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ACPlayer_YH::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPlayer_YH::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayer_YH::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer_YH::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer_YH::OnMoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ACPlayer_YH::OnHorizontalLook);
	PlayerInputComponent->BindAxis("Lookup", this, &ACPlayer_YH::OnVerticalLook);

	PlayerInputComponent->BindAction("Running", EInputEvent::IE_Pressed, this, &ACPlayer_YH::OnRunning);
	PlayerInputComponent->BindAction("Running", EInputEvent::IE_Released, this, &ACPlayer_YH::OffRunning);

}

void ACPlayer_YH::OnMoveForward(float Axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ACPlayer_YH::OnMoveRight(float Axis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, Axis);
}

void ACPlayer_YH::OnHorizontalLook(float Axis)
{
	AddControllerYawInput(Axis);
}

void ACPlayer_YH::OnVerticalLook(float Axis)
{
	AddControllerPitchInput(Axis);
}

void ACPlayer_YH::OnRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 600;
}

void ACPlayer_YH::OffRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 400;
}

