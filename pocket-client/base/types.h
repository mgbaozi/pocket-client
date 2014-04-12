#ifndef POCKET_BASE_TYPE_H
#define POCKET_BASE_TYPE_H
#include <vector>
#include <functional>
namespace pocket
{
struct Image
{
	unsigned int width, height;
	std::vector<unsigned char> data;
};
typedef std::shared_ptr<Image> ImagePtr;

typedef std::function<void (void)> VoidFunction;
	
} //namespace pocket
#endif
