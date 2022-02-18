#pragma once

#include <string>
#include <vector>

namespace net {
    namespace derpaul {
        namespace dicosto {
            namespace defines {
                // *****************************************************************************
                // Define byte
                using Byte = unsigned char;
                // Define adress type
                using BlockAddress = unsigned long long;
                // Define container
                using ContainerData = std::vector<unsigned char>;
                // *****************************************************************************
                // *****************************************************************************
                // Container related definitions
                // *****************************************************************************
                // Default block size in bytes
                static const unsigned int ContainerDefaultBlockSize = 1024;

                // Default container size in kilo bytes
                static const unsigned long ContainerDefaultContainerSize = 100;

                // Default name of a container
                static const std::string ContainerDefaultName = "Container1st.dta";

                // *****************************************************************************
                // Logger related definitions
                // *****************************************************************************
                // Default name of log file
                static const std::string LoggerDefaultFilename = "dicosto_test.log";
            }
        }
    }
}
