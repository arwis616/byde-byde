#include "CardTypes.h"

TArray<FCardData> UCardTypes::CreateStarterDeck(int32 Count, UTexture2D* DefaultIcon)
{
	TArray<FCardData> NewDeck;

	for (int32 i = 1; i <= Count; i++) 
	{
		
		FCardData NewCard;

		FString NameString = FString::Printf(TEXT("C++ Card %d"), i);
		NewCard.DisplayName = FText::FromString(NameString);
		NewCard.ManaCost = FMath::RandRange(1, 10);
		NewCard.Icon = DefaultIcon;
		NewCard.Element = static_cast<ECardElement>(i % 4 + 1);

		NewDeck.Add(NewCard);
	}

	return NewDeck;
}
