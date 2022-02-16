#include "Defines.h"

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // Container related definitions
            // *****************************************************************************
            // Default block size in bytes
            const unsigned int Defines::ContainerDefaultBlockSize = 1024;

            // Default container size in kilo bytes
            const unsigned long Defines::ContainerDefaultContainerSize = 100;

            // Default name of a container
            // TODO: Use mask instead of fixed name
            const std::string Defines::ContainerDefaultName = "Container1st.dta";

            // *****************************************************************************
            // Logger related definitions
            // *****************************************************************************
            // Default name of log file
            const std::string Defines::LoggerDefaultFilename = "dicosto_test.log";
        }
    }
}
