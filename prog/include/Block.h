#pragma once

#include <array>
#include "Defines.h"

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // http://www.cplusplus.com/forum/beginner/155821/
            // *****************************************************************************
            class Block {
            public:
                // *****************************************************************************
                static const unsigned char getBytes1(const defines::ContainerData& data, const defines::BlockAddress& position);
                // *****************************************************************************
                static const unsigned short getBytes2(const defines::ContainerData& data, const defines::BlockAddress& position);
                // *****************************************************************************
                static const unsigned long getBytes4(const defines::ContainerData& data, const defines::BlockAddress& position);
                // *****************************************************************************d
                static const unsigned long long getBytes8(const defines::ContainerData& data, const defines::BlockAddress& position);
                // *****************************************************************************
                static void setBytes1(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned char& val);
                // *****************************************************************************
                static void setBytes2(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned short& val);
                // *****************************************************************************
                static void setBytes4(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned long& val);
                // *****************************************************************************
                static void setBytes8(defines::ContainerData& data, const defines::BlockAddress& position, const unsigned long long& val);
                // *****************************************************************************
            protected:
                // *****************************************************************************
                static std::string getBytes(const defines::ContainerData& data, const defines::BlockAddress& position, const int& bytes);
                // *****************************************************************************
                static void setBytes(defines::ContainerData& data, const defines::BlockAddress& position, const std::string& val);
                // *****************************************************************************

                // *****************************************************************************
                template< typename T > std::array< defines::Byte, sizeof(T) >  to_bytes(const T& object)
                {
                    std::array< defines::Byte, sizeof(T) > bytes;

                    const defines::Byte* begin = reinterpret_cast<const defines::Byte*>(std::addressof(object));
                    const defines::Byte* end = begin + sizeof(T);
                    std::copy(begin, end, std::begin(bytes));

                    return bytes;
                }
                // *****************************************************************************
                template< typename T >
                T& from_bytes(const std::array< defines::Byte, sizeof(T) >& bytes, T& object)
                {
                    // http://en.cppreference.com/w/cpp/types/is_trivially_copyable
                    static_assert(std::is_trivially_copyable<T>::value, "not a TriviallyCopyable type");

                    defines::Byte* begin_object = reinterpret_cast<defines::Byte*>(std::addressof(object));
                    std::copy(std::begin(bytes), std::end(bytes), begin_object);

                    return object;
                }
                // *****************************************************************************
            };
        }
    }
}
