// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BreakableActor.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class CODINGPROJECT_API ABreakableActor : public AActor , public IHitInterface
{
	GENERATED_BODY()
	
public:	

	ABreakableActor();
	virtual void Tick(float DeltaTime) override;
	void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) ;
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite )
	class UCapsuleComponent* Capsule;
private:	
	
	
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class ATreasure>> TreasureClasses;

	
	

};
