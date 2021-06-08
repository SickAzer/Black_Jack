
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

Deck::Deck()
{
	m_Cards.reserve(52);
	Fill();
}

Deck::~Deck()
{
}

void Deck::Fill()
{
	Clear();
	for (int s = Card::DIAMONDS; s <= Card::CLUBS; ++s)
	{
		for (int v = Card::ACE; v <= Card::KING; ++v)
		{
			Add(new Card(static_cast<Card::value>(v), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		cout << "No more cards. Cannot deal.";
	}
}


void Deck::ExtraCards(AbstractPlayer& anAbstractPlayer)
{
	cout << "\n";

	while (!(anAbstractPlayer.TooMuch()) && anAbstractPlayer.WantsMore())
	{
	Deal(anAbstractPlayer);
	cout << anAbstractPlayer << endl;
	if (anAbstractPlayer.TooMuch())
	{
		anAbstractPlayer.Lost();
	}
	}
}
