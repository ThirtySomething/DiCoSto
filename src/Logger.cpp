#include "Logger.h"

#include <plog/Initializers/RollingFileInitializer.h>

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // Encapsulate logging variables in own namespace
            // *****************************************************************************
            namespace plog_variables {
                // *****************************************************************************
                // Global variable of logging severity
                // *****************************************************************************
                static plog::Severity g_logSeverity = plog::severityFromString("debug");
                // *****************************************************************************
                // Global variable of log filename
                // *****************************************************************************
                static std::string g_logFilename = net::derpaul::dicosto::Defines::LoggerDefaultFilename;
                // *****************************************************************************
                // Global variable of log appender
                // *****************************************************************************
                static std::unique_ptr<plog::IAppender> g_logAppender;
                // *****************************************************************************
                // Global variable of log instance
                // *****************************************************************************
                static std::unique_ptr<plog::Logger<PLOG_DEFAULT_INSTANCE_ID>> g_logInstance;
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Logger::logFilenameGet(void) {
                return plog_variables::g_logFilename;
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Logger::logFilenameSet(const std::string& fileName) {
                plog_variables::g_logFilename = fileName;
                return Logger::logFilenameGet();
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Logger::logInit(void) {
                if (nullptr != plog_variables::g_logInstance.get()) {
                    Logger::logStop();
                }
                plog_variables::g_logAppender.reset(new plog::RollingFileAppender<plog::TxtFormatter>(Logger::logFilenameGet().c_str(), 10000, 5));
                plog_variables::g_logInstance.reset(new plog::Logger<PLOG_DEFAULT_INSTANCE_ID>(plog_variables::g_logSeverity));
                plog_variables::g_logInstance->addAppender(plog_variables::g_logAppender.get());
                return Logger::logFilenameGet();
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Logger::logInit(const std::string& fileName) {
                Logger::logFilenameSet(fileName);
                return Logger::logInit();
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Logger::logSeverityGet(void) {
                std::string severity = plog::severityToString(plog_variables::g_logInstance->getMaxSeverity());
                return severity;
            }

            // *****************************************************************************
            // *****************************************************************************
            void Logger::logSeveritySet(const std::string& severity) {
                plog_variables::g_logSeverity = plog::severityFromString(severity.c_str());
            }

            // *****************************************************************************
            // *****************************************************************************
            void Logger::logStop(void) {
                plog_variables::g_logInstance.reset();
                plog_variables::g_logAppender.reset();
            }

            // *****************************************************************************
            // *****************************************************************************
        }
    }
}
