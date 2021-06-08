
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

#include "AbstractPlayer.h"
#include "Card.h"
#include "Casino.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const AbstractPlayer& anAbstractPlayer);

int main()
{
    cout << "Welcome to Blackjack!\n\n";
    int sumPlayers = 0;
    while (sumPlayers < 1 || sumPlayers > 5)
    {
        cout << "How many players? (5 max):";
        cin >> sumPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < sumPlayers; ++i)
    {
        cout << "Enter the name of the player " << i + 1 <<  " : ";
        cin >> name;
        names.push_back(name);
    }
    cout << "\n";

    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << endl << "Do you want to play again? (y/n): ";
        cin >> again;
    }
    cout << "Thank you for playing. Goodbye!\n\n";
    return 0;

}

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string VALUES[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const string SUITS[] = { "d", "c", "h", "s" };

    if (aCard.m_FaceUp)
    {
        os << VALUES[aCard.m_Value] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }
    return os;
}

ostream& operator<<(ostream& os, const AbstractPlayer& anAbstractPlayer)
{
    os << anAbstractPlayer.m_Name << ":\t";
    vector<Card*>::const_iterator pCard;
    if (!anAbstractPlayer.m_Cards.empty())
    {
        for (pCard = anAbstractPlayer.m_Cards.begin(); pCard != anAbstractPlayer.m_Cards.end(); ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        if (anAbstractPlayer.GetTotal() != 0)
        {
            cout << "(" << anAbstractPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    return os;
}
