namespace pocket
{

namespace model
{

class Card
{
public:
	Card(unsigned int id);
	Card(const Card& card);
private:
	enum Type
	{
		MINION = 1,
		SPELL,
		WEAPON
	};
	void init();
	unsigned int box_;
	unsigned int image_;
	unsigned int introduction_;
	unsigned int id_;
};

} // namespace model

} // namespace pocket
