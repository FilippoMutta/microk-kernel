#include <container.hpp>

namespace CONTAINERS {
Container *InitializeContainer(uptr containerFrame) {
	Container *container = (Container*)containerFrame;

	return container;
}
}
