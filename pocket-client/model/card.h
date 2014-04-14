#ifndef POCKET_MODEL_CARD_H
#define POCKET_MODEL_CARD_H
#include "../base/types.h"
namespace pocket
{

namespace model
{

class Card
{
public:
	Card(unsigned int id);
	Card(const Card& card);
	inline uint32_t get_box_id() const
	{
		return box_;
	}
	inline uint32_t get_image_id() const
	{
		return image_;
	}
	inline uint32_t get_introduction_id() const
	{
		return introduction_;
	}
private:
	enum Type
	{
		MINION = 1,
		SPELL,
		WEAPON
	};
	void init();
	uint32_t box_;
	uint32_t image_;
	uint32_t introduction_;
	uint32_t id_;
};

} // namespace model

} // namespace pocket
#endif
