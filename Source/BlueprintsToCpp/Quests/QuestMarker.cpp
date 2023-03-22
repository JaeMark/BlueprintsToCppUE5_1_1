// FILE: QuestMarker.cpp

#include "QuestMarker.h"
#include "NiagaraComponent.h"

// Sets default values
AQuestMarker::AQuestMarker() {
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	NiagaraSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraSystem"));

	SetRootComponent(Root);
	NiagaraSystem->SetupAttachment(Root);

	// Wasn't able to set user parameters from Blueprint, which is frustrating.
	NiagaraSystem->SetVariableVec3(TEXT("Vector (RGB)_Color"), FVector3d{ 1.0, 0.0, 0.090841 });
}

void AQuestMarker::BeginPlay() {
	GetQuestManager()->CompletedQuest.AddDynamic(this, &AQuestMarker::QuestUpdate);
	RefreshVisibility();
}

void AQuestMarker::RefreshVisibility() {
	const FQuestInfo Quest = GetQuestManager()->GetQuest(QuestName);
	const bool Visibility = GetQuestManager()->IsActiveQuest(QuestName) && Quest.Progress == ShowAtProgress;
	NiagaraSystem->SetVisibility(Visibility);
}

void AQuestMarker::QuestUpdate(int32 index) {
	RefreshVisibility();
}