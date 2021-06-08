#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

Casino::Casino(const string& name): AbstractPlayer(name)
{
}

Casino::~Casino()
{
}

bool Casino::WantsMore() const
{
    return (GetTotal() <= 16);
}

void Casino::TurnFirstCard()
{
    if (!(m_Cards.empty()))
    {
        m_Cards[0]->Flip();
    }
    else
    {
        cout << "No cards to show!\n";
    }
}
