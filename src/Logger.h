#pragma once

#include <plog/Severity.h>

#include "Defines.h"

namespace net {
namespace derpaul {
namespace dicosto {
class Logger {
   public:
    // *************************************************************************
    static DICOSTO_STR logInit(void);
    // *************************************************************************
    static DICOSTO_STR logInit(const DICOSTO_STR &fileName);
    // *************************************************************************
    static DICOSTO_STR logFilenameGet(void);
    // *************************************************************************
    static DICOSTO_STR logFilenameSet(const DICOSTO_STR &fileName);
    // *************************************************************************
    static void logVerbose(const DICOSTO_STR &message);
    // *************************************************************************
    static void logDebug(const DICOSTO_STR &message);
    // *************************************************************************
    static void logInfo(const DICOSTO_STR &message);
    // *************************************************************************
    static void logWarning(const DICOSTO_STR &message);
    // *************************************************************************
    static void logError(const DICOSTO_STR &message);
    // *************************************************************************
    static void logFatal(const DICOSTO_STR &message);
    // *************************************************************************
    static void logNone(const DICOSTO_STR &message);
    // *************************************************************************

   protected:
    // *************************************************************************
    static void log(const plog::Severity &severity, const DICOSTO_STR &message);
    // *************************************************************************
    static DICOSTO_STR logfileName;
    // *************************************************************************
};
}  // namespace dicosto
}  // namespace derpaul
}  // namespace net
