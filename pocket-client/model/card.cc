#include "card.h"
using namespace pocket;
using namespace pocket::model;

Card::Card(unsigned int id)
	:id_(id)
{

}

Card::Card(const Card& card)
	:id_(card.id_)
{

}

void Card::init()
{
}
