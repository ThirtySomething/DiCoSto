#pragma once

#include <plog/Appenders/RollingFileAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Log.h>

#include "Defines.h"

namespace net {
    namespace derpaul {
        namespace dicosto {
            class Logger {
            public:
                // *****************************************************************************
                static std::string logInit(void);
                // *****************************************************************************
                static std::string logInit(const std::string& fileName);
                // *****************************************************************************
                static std::string logFilenameGet(void);
                // *****************************************************************************
                static std::string logFilenameSet(const std::string& fileName);
                // *****************************************************************************
                static std::string logSeverityGet(void);
                // *****************************************************************************
                static void logSeveritySet(const std::string& severity);
                // *****************************************************************************
                static void logStop(void);
                // *****************************************************************************
            };
        }
    }
}
