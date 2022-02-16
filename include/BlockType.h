#pragma once

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            enum class BlockType {
                Unknown = 0x00,
                MetaContainer = 0x01,
                MetaDirectory = 0x02,
                DataBlock = 0x03
            };
            // *****************************************************************************
        }
    }
}
