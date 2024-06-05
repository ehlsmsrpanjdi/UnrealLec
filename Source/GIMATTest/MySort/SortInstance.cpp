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
	if (SortTime < 2.f) {
		SortTime += _DeltaTime;
	}
	else {
		SortTime = 0.f;
		for (uint16 i = 0; i < Count; ++i) {
			for (uint16 j = i + 1; j < Count; ++j) {
				if (AllSortObjects[i]->Height > AllSortObjects[j]->Height) {
					AllSortObjects[i]->Select();
					AllSortObjects[j]->Select();
					AllSortObjects[i]->Swap(AllSortObjects[j]);
					break;
				}
			}
		}
	}

}
