#include "card.h"
using namespace pocket;
using namespace pocket::model;

Card::Card(unsigned int id)
	:id_(id)
{
	init();
}

Card::Card(const Card& card)
	:id_(card.id_)
{

}

void Card::init()
{
	//FIXME:这里是测试代码，固定加载图片
	box_ = 1;
	image_ = 2;
	introduction_ = 1;
}
