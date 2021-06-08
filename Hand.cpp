#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

Hand::Hand()
{
	m_Cards.reserve(5);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	if (m_Cards.empty())
	{
		return 0;
	}
	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}
	bool haveAnAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			haveAnAce = true;
		}
	}
	if (haveAnAce && total <= 11)
	{
		total += 10;
	}
	return total;
}
