// Fill out your copyright notice in the Description page of Project Settings.


#include "MySort/SortObject.h"
#include "SortInstance.h"

// Sets default values
ASortObject::ASortObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TESTMESH"));
}

// Called when the game starts or when spawned
void ASortObject::BeginPlay()
{
	Super::BeginPlay();
	USortInstance* GI = Cast<USortInstance>(GetGameInstance());
	GI->PushSortObject(this);
	//Height = GetActorScale().Y;
}

// Called every frame
void ASortObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

