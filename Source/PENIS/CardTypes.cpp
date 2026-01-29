#include "CardTypes.h"

TArray<FCardData> UCardTypes::CreateStarterDeck(int32 Count, UTexture2D* DefaultIcon)
{
	TArray<FCardData> NewDeck;

	for (int32 i = 1; i <= Count; i++)
	{
		FCardData NewCard;

		// нейм и иконка
		FString NameString = FString::Printf(TEXT("Card %d"), i);
		NewCard.DisplayName = FText::FromString(NameString);
		NewCard.Icon = DefaultIcon;

		// рандомная цена маны(1-5)
		NewCard.ManaCost = FMath::RandRange(1, 5);

		// рандомное действие (0 - дмг, 1 - хилл, 2 - щит)
		int32 RandomAction = FMath::RandRange(0, 2);
		NewCard.ActionType = static_cast<ECardAction>(RandomAction);

		// рандомная сила (5-15)
		NewCard.EffectValue = FMath::RandRange(5, 15);

		NewCard.Element = static_cast<ECardElement>((i % 4) + 1);

		NewDeck.Add(NewCard);
	}

	return NewDeck;
}

bool UCardTypes::CanPlayCard(int32 CurrentMana, int32 CardCost)
{
	if (CurrentMana >= CardCost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UCardTypes::ProcessCardAction(ECardAction Action, int32 Power, int32 CurrentEnemyHP, int32 CurrentPlayerHP, int32& OutEnemyHP, int32& OutPlayerHP)
{
	OutEnemyHP = CurrentEnemyHP;
	OutPlayerHP = CurrentPlayerHP;

	// проверка типа карты
	switch (Action)
	{
	case ECardAction::Damage:
		OutEnemyHP = CurrentEnemyHP - Power; // отнимаем, если дмг
		if (OutEnemyHP < 0) OutEnemyHP = 0;  // чтобы не уходило в минус
		break;

	case ECardAction::Heal:
		OutPlayerHP = CurrentPlayerHP + Power; // прибавляем, если хилл
		// можно добавить ограничение по макс хп позже
		break;

	case ECardAction::Shield:
		// логика щита позже
		break;
	}
}