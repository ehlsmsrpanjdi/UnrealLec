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
	if (SortTime <= 0.1f) {
		SortTime += _DeltaTime;
	}
	else {
		SortTime = 0.f;
			if (SecondIndex <= Count - 1) {
				AllSortObjects[FirstIndex]->Select();
				AllSortObjects[SecondIndex]->Select();
				if (AllSortObjects[SecondIndex]->Height < AllSortObjects[FirstIndex]->Height) {
					AllSortObjects[SecondIndex]->Swap(AllSortObjects[FirstIndex]);
					ASortObject* Temp = nullptr;
					Temp = AllSortObjects[SecondIndex];
					AllSortObjects[SecondIndex] = AllSortObjects[FirstIndex];
					AllSortObjects[FirstIndex] = Temp;
				}
				++SecondIndex;
			}
			else {
				++FirstIndex;
				SecondIndex = FirstIndex + 1;
				if (FirstIndex == Count - 1) {
					SortEnd = true;
				}
			}
		}
	}
