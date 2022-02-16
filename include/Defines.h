#pragma once

#include <string>

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // Define adress type
            typedef unsigned long long BlockAddress;
            // *****************************************************************************
            class Defines {
            public:
                // *****************************************************************************
                // Container related definitions
                // *****************************************************************************
                // Default block size in bytes
                static const unsigned int ContainerDefaultBlockSize;

                // Default container size in kilo bytes
                static const unsigned long ContainerDefaultContainerSize;

                // Default name of a container
                static const std::string ContainerDefaultName;

                // *****************************************************************************
                // Logger related definitions
                // *****************************************************************************
                // Default name of log file
                static const std::string LoggerDefaultFilename;
            };
        }
    }
}
