// FILE: QuestMarker.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestMarker.generated.h"

class UNiagaraComponent; // Forward declaration. Ask Kyle about this.

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestMarker();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UNiagaraComponent* NiagaraSystem;
};