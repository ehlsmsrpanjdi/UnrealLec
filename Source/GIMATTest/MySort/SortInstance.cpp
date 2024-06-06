// Fill out your copyright notice in the Description page of Project Settings.


#include "MySort/SortInstance.h"
#include "MySort/SortObject.h"

USortInstance::USortInstance() {

}

void USortInstance::PushSortObject(ASortObject* _Object)
{
	AllSortObjects.Push(_Object);
	_Object->SetActorLocation(StartLocation);
	_Object->AddActorLocalOffset(FVector(Count * 200, 0.f, 0.f));
	_Object->SetActorScale3D(FVector(1.f, 1.f, Height));
	_Object->SetHeight(Height);
	++Count;
}

void USortInstance::SpawnSortingObject()
{
	GetWorld()->SpawnActor<ASortObject>(SortObject);
}

void USortInstance::Sort(float _DeltaTime)
{
	if (SortEnd == true) {
		return;
	}
	if (SortTime <= 1.f) {
		SortTime += _DeltaTime;
	}
	else {
		SortTime = 0.f;
		if (FirstBool != true) {
			FirstBool = true;
			if (FirstIndex <= Count) {
				++FirstIndex;
				AllSortObjects[FirstIndex]->Select();
			}
			else {
				++Loop;
				FirstIndex = Loop;
				if (Loop >= Count) {
					SortEnd = true;
				}
			}
		}
		else {
			if (SecondIndex <= Count) {
				++SecondIndex;
				AllSortObjects[FirstIndex]->Select();
				AllSortObjects[SecondIndex]->Select();
				if (AllSortObjects[SecondIndex]->Height < AllSortObjects[FirstIndex]->Height) {
					AllSortObjects[SecondIndex]->Swap(AllSortObjects[FirstIndex]);
				}
			}
			else {
				SecondIndex = Loop + 1;
				FirstBool = false;
			}
		}
	}
}
