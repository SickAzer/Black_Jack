#pragma once

#include "AbstractPlayer.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Casino : public AbstractPlayer
{
public:
	Casino(const string& name = "Casino");
	virtual ~Casino();

	virtual bool WantsMore() const;
	void TurnFirstCard();
};
