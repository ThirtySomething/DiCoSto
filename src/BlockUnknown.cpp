#include "BlockUnknown.h"

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // *****************************************************************************
            BlockUnknown::BlockUnknown(void) {
                std::unique_ptr<unsigned char[], std::default_delete<unsigned char[]>> bulkdata(new unsigned char[Defines::ContainerDefaultBlockSize]);
            }

            // *****************************************************************************
            // *****************************************************************************
            BlockUnknown::~BlockUnknown(void) {
            }

            // *****************************************************************************
            // *****************************************************************************
            BlockType BlockUnknown::getBlockType(void) {
                BlockType btype = BlockType::Unknown;

                switch (bulkdata[0]) {
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
