#pragma once

#include "BlockType.h"
#include "Defines.h"
#include <memory>
#include <vector>

namespace net {
    namespace derpaul {
        namespace dicosto {
            class BlockUnknown {
            public:
                // *****************************************************************************
                BlockUnknown(const BlockType& blocktype = BlockType::Unknown);
                // *****************************************************************************
                ~BlockUnknown(void);
                // *****************************************************************************
                BlockType getBlockType(void);
                // *****************************************************************************
            protected:
                // *****************************************************************************
                std::unique_ptr<defines::ContainerData> bulkdata;
                // *****************************************************************************
            };
        }
    }
}
