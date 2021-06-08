#pragma once
#include "Hand.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbstractPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const AbstractPlayer& anAbstractPlayer);
public:
	AbstractPlayer(const string& name = "");
	virtual ~AbstractPlayer();

	virtual bool WantsMore() const = 0;
	bool TooMuch() const;
	void Lost() const;
protected:
	string m_Name;
};

