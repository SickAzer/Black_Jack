#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

Game::Game(const vector<string>& names)
{
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(Player(*pName));
	}
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Fill();
	m_Deck.Shuffle();
}

Game::~Game()
{
}

void Game::Play()
{
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_Casino);
	}
	m_Casino.TurnFirstCard();
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		cout << *pPlayer << endl;
	}
	cout << m_Casino << endl;

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.ExtraCards(*pPlayer);
	}
	m_Casino.TurnFirstCard();
	cout << endl << m_Casino;
	m_Deck.ExtraCards(m_Casino);
	if (m_Casino.TooMuch())
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->TooMuch()))
			{
				pPlayer->Win();
			}
		}
	}
	else
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (pPlayer->GetTotal() > m_Casino.GetTotal())
			{
				pPlayer->Win();
			}
			else if (pPlayer->GetTotal() < m_Casino.GetTotal())
			{
				pPlayer->Lose();
			}
			else
			{
				pPlayer->Draw();
			}

		}
	}
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		pPlayer->Clear();
	}
	m_Casino.Clear();
}

