#include "resource.h"
#include "types.h"
#include <assert.h>

using namespace pocket;
using namespace model;

int main()
{
	Resource& resource = Resource::instance();
	ImagePtr image = resource.get_image(1);
	assert(image.get() != nullptr);
	return 0;
}
