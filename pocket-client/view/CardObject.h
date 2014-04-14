#ifndef POCKET_VIEW_CARD_OBJECT_H
#define POCKET_VIEW_CARD_OBJECT_H
#include "ViewObject.h"
#include "../model/resource.h"
#include "../model/card.h"
namespace pocket
{

namespace view
{

class CardObject : public ViewObject
{
public:
	CardObject(const model::Card& card);
	~CardObject();

private:
	void init();

private:
	const model::Card& card_;
	model::Resource& resource_;

};
} // namespace view
} // namespace pocket

#endif
