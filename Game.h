#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"


using namespace std;

class Game
{
public:
	Game(const vector<string>& names);
	~Game();

	void Play();
private:
	Deck m_Deck;
	Casino m_Casino;
	vector<Player> m_Players;
};

