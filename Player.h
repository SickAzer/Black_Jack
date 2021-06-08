#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "AbstractPlayer.h"

using namespace std;

class Player : public AbstractPlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();

	virtual bool WantsMore() const;
	void Win() const;
	void Lose() const;
	void Draw() const;
};

