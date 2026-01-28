#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/Texture2D.h"
#include "CardTypes.generated.h" // ЭТОТ INCLUDE ВСЕГДА ДОЛЖЕН БЫТЬ ПОСЛЕДНИМ!

// --- 1. ENUMS ---

UENUM(BlueprintType)
enum class ECardRarity : uint8
{
	Common UMETA(DisplayName = "Common"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary"),
	Mythic UMETA(DisplayName = "Mythic")
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

// --- 2. STRUCT ---

USTRUCT(BlueprintType)
struct FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	int32 ManaCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	ECardRarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	ECardElement Element;

	// Конструктор
	FCardData()
	{
		ManaCost = 0;
		Rarity = ECardRarity::Common;
		Element = ECardElement::None;
		Icon = nullptr;
	}
};

// --- 3. CLASS ---

UCLASS()
class PENIS_API UCardTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Card Game C++")
	static TArray<FCardData> CreateStarterDeck(int32 Count, UTexture2D* DefaultIcon);

	// Проверка маны
	UFUNCTION(BlueprintCallable, Category = "Card Game C++") 
	static bool CanPlayCard(int32 CurrentMana, int32 CardCost);
};