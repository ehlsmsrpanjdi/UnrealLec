// Fill out your copyright notice in the Description page of Project Settings.


#include "MySort/SortObject.h"
#include "SortInstance.h"

// Sets default values
ASortObject::ASortObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TESTMESH"));
	SelectMaterial = CreateDefaultSubobject<UMaterial>(TEXT("SelectMaterial"));
	NoneSelectMaterial = CreateDefaultSubobject<UMaterial>(TEXT("NoneSelectMaterial"));
}

// Called when the game starts or when spawned
void ASortObject::BeginPlay()
{
	Super::BeginPlay();
	MyMesh->SetMaterial(0, NoneSelectMaterial);
	USortInstance* GI = Cast<USortInstance>(GetGameInstance());
	GI->PushSortObject(this);
}

// Called every frame
void ASortObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (true == Selected) {
		SelectedTime += DeltaTime;
		if (SelectedTime >= 1.f) {
			NoneSelect();
			SelectedTime = 0.f;
		}
	}
}
