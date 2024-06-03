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

	void PushSortObject(ASortObject* _Object) {
		AllSortObjects.Push(_Object);
	}
private:
	TArray<ASortObject*> AllSortObjects = { nullptr ,};
};
