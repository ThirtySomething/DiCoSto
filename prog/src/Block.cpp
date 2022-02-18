#include "Block.h"
#include "DataSize.h"
#include <cstdlib>
#include <string>
#include "Logger.h"

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // *****************************************************************************
            const unsigned char Block::getBytes1(const defines::ContainerData& data, const defines::BlockAddress& position) {
                int bytes = static_cast<int>(DataSize::BYTES_01);
                std::string valraw = Block::getBytes(data, position, bytes);
                return valraw[0];
            }

            // *****************************************************************************
            // *****************************************************************************
            const unsigned short Block::getBytes2(const defines::ContainerData& data, const defines::BlockAddress& position) {
                int bytes = static_cast<int>(DataSize::BYTES_02);
                PLOGD << "bytes [" << bytes << "]";
                std::string valraw = Block::getBytes(data, position, bytes);
                PLOGD << "valraw [" << valraw.c_str() << "]";
                int dummy = valraw.length();
                PLOGD << "dummy [" << dummy << "]";
                unsigned long val = std::stoul("" == valraw ? "0" : valraw);
                return static_cast<unsigned short>(val);
            }

            // *****************************************************************************
            // *****************************************************************************
            const unsigned long Block::getBytes4(const defines::ContainerData& data, const defines::BlockAddress& position) {
                int bytes = static_cast<int>(DataSize::BYTES_04);
                std::string valraw = Block::getBytes(data, position, bytes);
                unsigned long result = std::stol(valraw);
                return result;
            }

            // *****************************************************************************
            // *****************************************************************************
            const unsigned long long Block::getBytes8(const defines::ContainerData& data, const defines::BlockAddress& position) {
                int bytes = static_cast<int>(DataSize::BYTES_08);
                std::string valraw = Block::getBytes(data, position, bytes);
                unsigned long long result = std::stoll(valraw);
                return result;
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Block::getBytes(const defines::ContainerData& data, const defines::BlockAddress& position, const int& bytes) {
                defines::ContainerData tmpdata(&data[position], &data[position + bytes]);
                std::string result(tmpdata.begin(), tmpdata.end());
                return result;
            }

            // *****************************************************************************
            // *****************************************************************************
            void Block::setBytes1(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned char& val) {
                std::string strval(1, val);
                Block::setBytes(data, position, strval);
            }

            // *****************************************************************************
            // *****************************************************************************
            void Block::setBytes2(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned short& val) {
                int bytes = static_cast<int>(DataSize::BYTES_02);
                std::string strval = std::to_string(val);
                strval.insert(strval.begin(), bytes - strval.size(), '0');
                Block::setBytes(data, position, strval);
            }

            // *****************************************************************************
            // *****************************************************************************
            void Block::setBytes4(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned long& val) {
                int bytes = static_cast<int>(DataSize::BYTES_04);
                std::string strval = std::to_string(val);
                strval.insert(strval.begin(), bytes - strval.size(), '0');
                Block::setBytes(data, position, strval);
            }

            // *****************************************************************************
            // *****************************************************************************
            void Block::setBytes8(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned long long& val) {
                int bytes = static_cast<int>(DataSize::BYTES_08);
                std::string strval = std::to_string(val);
                strval.insert(strval.begin(), bytes - strval.size(), '0');
                Block::setBytes(data, position, strval);
            }

            // *****************************************************************************
            // *****************************************************************************
            void Block::setBytes(defines::ContainerData& data, const defines::BlockAddress& position, const std::string& val) {
                defines::ContainerData tmpval(val.begin(), val.end());
                std::copy(tmpval.begin(), tmpval.end(), data.begin() + position);
            }
        }
    }
}
