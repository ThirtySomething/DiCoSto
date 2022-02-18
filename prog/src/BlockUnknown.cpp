#include "BlockUnknown.h"

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // *****************************************************************************
            BlockUnknown::BlockUnknown(const BlockType& blocktype) {
                this->bulkdata = std::unique_ptr < defines::ContainerData>(new defines::ContainerData(defines::ContainerDefaultBlockSize, 0));
                (*this->bulkdata)[0] = static_cast<char>(blocktype);
            }

            // *****************************************************************************
            // *****************************************************************************
            BlockUnknown::~BlockUnknown(void) {
            }

            // *****************************************************************************
            // *****************************************************************************
            BlockType BlockUnknown::getBlockType(void) {
                BlockType btype = BlockType::Unknown;

                switch ((*this->bulkdata)[0]) {
                case 0x01:
                    btype = BlockType::MetaContainer;
                    break;
                case 0x02:
                    btype = BlockType::MetaDirectory;
                    break;
                case 0x03:
                    btype = BlockType::DataBlock;
                    break;
                case 0x00:
                default:
                    btype = BlockType::Unknown;
                }

                return btype;
            }
        }
    }
}
