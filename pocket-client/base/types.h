#ifndef POCKET_BASE_TYPE_H
#define POCKET_BASE_TYPE_H
#include <vector>
namespace pocket
{
struct Image
{
	unsigned int width, height;
	std::vector<unsigned char> data;
};
typedef std::shared_ptr<Image> ImagePtr;
	
} //namespace pocket
#endif
