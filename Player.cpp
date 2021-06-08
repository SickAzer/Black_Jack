#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

Player::Player(const string& name): AbstractPlayer(name)
{
}

Player::~Player()
{
}

bool Player::WantsMore() const
{
    cout << m_Name << ", do you want more? (y/n): ";
    char answer;
    cin >> answer;
    return (answer == 'Y' || answer == 'y');
}

void Player::Win() const
{
    cout << m_Name << " wins!\n";
}

void Player::Lose() const
{
    cout << m_Name << " loses!\n";
}

void Player::Draw() const
{
    cout << m_Name << " draws!\n";
}
