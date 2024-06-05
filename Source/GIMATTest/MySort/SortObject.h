// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SortObject.generated.h"

UCLASS()
class GIMATTEST_API ASortObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASortObject();

	/*UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UStaticMeshComponent> WhichMesh;*/

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MyMesh;

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UMaterial* SelectMaterial;

	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UMaterial* NoneSelectMaterial;
	
	void SetHeight(float _Height) {
		Height = _Height;
	}

	void Select() {
		MyMesh->SetMaterial(0, SelectMaterial);
		Selected = true;
	}

	void NoneSelect() {
		MyMesh->SetMaterial(0, NoneSelectMaterial);
		Selected = false;
	}

	UFUNCTION(BlueprintCallable)
	void Swap(ASortObject* _Object) {
		FVector Temp = _Object->GetActorLocation();
		_Object->SetActorLocation(GetActorLocation());
		SetActorLocation(Temp);
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Height;
	bool Selected = false;
	float SelectedTime = 0.f;
};
