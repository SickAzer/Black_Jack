#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

AbstractPlayer::AbstractPlayer(const string& name):m_Name(name)
{
}

AbstractPlayer::~AbstractPlayer()
{
}

bool AbstractPlayer::TooMuch() const
{
    return (GetTotal() > 21);
}

void AbstractPlayer::Lost() const
{
    cout << m_Name << " lost!\n";
}

