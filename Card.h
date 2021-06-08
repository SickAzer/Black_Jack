#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card
{
public:
	enum value
	{ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit { DIAMONDS, CLUBS, HEARTS, SPADES };

	friend ostream& operator<<(ostream& os, const Card& aCard);
	Card(value v = ACE, suit s = SPADES, bool up = true);
	int GetValue() const;
	void Flip();
private:
	value m_Value;
	suit m_Suit;
	bool m_FaceUp;
};


