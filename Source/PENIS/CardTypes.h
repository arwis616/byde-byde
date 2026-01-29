#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CardTypes.generated.h"

UENUM(BlueprintType)
enum class ECardAction : uint8
{
	Damage  UMETA(DisplayName = "Deal Damage"), // дмг
	Heal    UMETA(DisplayName = "Restore Health"), // хил
	Shield  UMETA(DisplayName = "Add Shield") // щит
};

UENUM(BlueprintType)
enum class ECardElement : uint8
{
	None UMETA(DisplayName = "None"),
	Fire UMETA(DisplayName = "Fire"),
	Water UMETA(DisplayName = "Water"),
	Earth UMETA(DisplayName = "Earth"),
	Air UMETA(DisplayName = "Air")
};

USTRUCT(BlueprintType)
struct FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ManaCost;

	// тип карты
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardAction ActionType;

	// сила
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 EffectValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardElement Element;
};

UCLASS()
class PENIS_API UCardTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Card Game C++")
	static TArray<FCardData> CreateStarterDeck(int32 Count, UTexture2D* DefaultIcon);

	UFUNCTION(BlueprintCallable, Category = "Card Game C++")
	static bool CanPlayCard(int32 CurrentMana, int32 CardCost);

	UFUNCTION(BlueprintCallable, Category = "Card Game C++")
	static void ProcessCardAction(ECardAction Action, int32 Power, int32 CurrentEnemyHP, int32 CurrentPlayerHP, int32& OutEnemyHP, int32& OutPlayerHP);
};