#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Hand.h"

using namespace std;

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();

	void Fill();
	void Shuffle();
	void Deal(Hand& aHand);
	void ExtraCards(AbstractPlayer& anAbstractPlayer);
};

