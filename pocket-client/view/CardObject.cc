#include "CardObject.h"

using namespace pocket;
using namespace view;
using namespace model;

CardObject::CardObject(const Card& card)
	:ViewObject(), card_(card), resource_(Resource::instance()),
	state_({0.0f, 0.0f, 0.1f, 0.2f, 0.0f})
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
	ImageObject box = {0.0f, 0.0f, 1.0f, 1.0f, resource_.get_image(box_id), 0};
	ImageObject image = {0.1f, 0.1f, 0.9f, 0.4f, resource_.get_image(image_id), 0};
	display_list_.push_back(image);
	display_list_.push_back(box);
}

