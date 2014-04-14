#include "CardObject.h"
using namespace pocket;
using namespace view;
using namespace model;

#include<fstream>
CardObject::CardObject(const Card& card)
	:ViewObject(ObjectState(0.0f, 0.0f, 0.12f, 0.3f, 0.8f)), card_(card), resource_(Resource::instance())
{
	init();
}

CardObject::~CardObject()
{

}

void CardObject::init()
{
	uint32_t box_id = card_.get_box_id();
	uint32_t image_id = card_.get_image_id();
	ImageObject box(0.0f, 0.0f, 1.0f, 0.5f, resource_.get_image(box_id), 0);
	ImageObject image(0.0f, 0.5f, 1.0f, 0.5f, resource_.get_image(image_id), 0);
	display_list_.push_back(image);
	display_list_.push_back(box);
}

