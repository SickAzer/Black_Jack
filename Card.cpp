
#include "Card.h"


Card::Card(value v, suit s, bool up): m_Value(v), m_Suit(s), m_FaceUp(up)
{
}

int Card::GetValue() const
{
	int value = 0;
	if (m_FaceUp)
	{
		value = m_Value;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_FaceUp = !(m_FaceUp);
}


