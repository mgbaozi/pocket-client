namespace pocket
{

namespace model
{

class Card
{
public:
	Card(unsigned int id);
	Card(const Card& card);
	inline uint32_t get_box_id()
	{
		return box_;
	}
	inline uint32_t get_image_id()
	{
		return image_;
	}
	inline uint32_t get_introduction_id()
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
