// FILE: QuestMarker.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.h"
#include "QuestMarker.generated.h"

class UNiagaraComponent; // Forward declaration. Ask Kyle about this.

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestMarker();

	UFUNCTION(BlueprintCallable)
		void RefreshVisibility();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void QuestUpdate(int32 index);


protected:
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
		AQuestManager* GetQuestManager();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UNiagaraComponent* NiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 ShowAtProgress = 0;
};