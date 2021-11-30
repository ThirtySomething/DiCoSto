#include "Container.h"
#include "Defines.h"

namespace net {
namespace derpaul {
namespace dicosto {
// *****************************************************************************
// *****************************************************************************
Container::Container(void) {
    this->containerName = DICOSTO_CONTAINER_DEFAULT_NAME;
}
// *****************************************************************************
// *****************************************************************************
Container::Container(const DICOSTO_STR& containerName) {
    this->containerName = containerName;
}
// *****************************************************************************
// *****************************************************************************
Container::~Container(void) {
}
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Container::containerNameGet(void) {
    return this->containerName;
}
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Container::containerNameSet(const DICOSTO_STR& containerName) {
    this->containerName = containerName;
    return this->containerName;
}
// *****************************************************************************
// *****************************************************************************
}  // namespace dicosto
}  // namespace derpaul
}  // namespace net
