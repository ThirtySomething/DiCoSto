#include "Logger.h"

#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Log.h>

namespace net {
namespace derpaul {
namespace dicosto {
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Logger::logfileName = DICOSTO_LOGGER_DEFAULT_FILENAME;
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Logger::logFilenameGet(void) {
    return Logger::logfileName;
}
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Logger::logFilenameSet(const DICOSTO_STR &fileName) {
    Logger::logfileName = fileName;
    return Logger::logFilenameGet();
}
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Logger::logInit(void) {
    plog::init(plog::debug, Logger::logfileName.c_str());
    return Logger::logFilenameGet();
}
// *****************************************************************************
// *****************************************************************************
DICOSTO_STR Logger::logInit(const DICOSTO_STR &fileName) {
    Logger::logFilenameSet(fileName);
    return Logger::logInit();
}
// *****************************************************************************
// *****************************************************************************
void Logger::logVerbose(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::verbose, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::logDebug(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::debug, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::logInfo(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::info, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::logWarning(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::warning, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::logError(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::error, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::logFatal(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::fatal, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::logNone(const DICOSTO_STR &message) {
    Logger::log(plog::Severity::none, message);
}
// *****************************************************************************
// *****************************************************************************
void Logger::log(const plog::Severity &severity, const DICOSTO_STR &message) {
    PLOG(severity) << message.c_str();
}
// *****************************************************************************
// *****************************************************************************
}  // namespace dicosto
}  // namespace derpaul
}  // namespace net
