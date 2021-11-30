#pragma once

#include "Defines.h"

namespace net {
namespace derpaul {
namespace dicosto {
class Container {
   public:
    // *************************************************************************
    Container(void);
    // *************************************************************************
    Container(const DICOSTO_STR& containerName);
    // *************************************************************************
    ~Container(void);
    // *************************************************************************
    DICOSTO_STR containerNameGet(void);
    // *************************************************************************
    DICOSTO_STR containerNameSet(const DICOSTO_STR& containerName);
    // *************************************************************************

   protected:
    // *************************************************************************
    DICOSTO_STR containerName;
    // *************************************************************************
};
}  // namespace dicosto
}  // namespace derpaul
}  // namespace net
