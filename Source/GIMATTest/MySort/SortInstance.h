// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SortInstance.generated.h"

/**
 * 
 */
class ASortObject;
UCLASS()
class GIMATTEST_API USortInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	USortInstance();

	void PushSortObject(ASortObject* _Object);
	UFUNCTION(BlueprintCallable)
	void SpawnSortingObject();

	UFUNCTION(BlueprintCallable)
	void Sort(float _DeltaTime);
private:
	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<ASortObject*> AllSortObjects;

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ASortObject> SortObject;

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int Count = 0;

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Height = 0;

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FVector StartLocation = FVector::Zero();

	int FirstIndex = 0;
	bool FirstBool;
	int SecondIndex = 1;
	bool SecondBool;
	int Loop = 0;
	bool SortEnd = false;
	float SortTime = 2.f;
	uint16 SelectNum = 0;
};
