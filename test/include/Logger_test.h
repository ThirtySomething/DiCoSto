#pragma once
#include <stdbool.h>
#include <catch2/catch.hpp>
#include <fstream>
#include "Defines.h"
#include "Logger.h"
#include "TestHelper.h"

// *****************************************************************************
// *****************************************************************************
// Group name of all tests here
static const char TestLogger[] = "[Logger]";

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test logger default filename", TestLogger) {
    GIVEN("Got fresh logger") {
        THEN("Initialize") {
            loggerReset(net::derpaul::dicosto::defines::LoggerDefaultFilename);
        }

        THEN("Check default logger filename") {
            // Read default logfile name
            std::string loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }

        WHEN("Check filename returned by initialization") {
            // Logfile name of init should be equal to default
            std::string loggerName = net::derpaul::dicosto::Logger::logInit();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test logger default severity", TestLogger) {
    GIVEN("Got fresh logger") {
        THEN("Initialize") {
            loggerReset(net::derpaul::dicosto::defines::LoggerDefaultFilename);
        }

        THEN("Check default logger severity") {
            // Read default logfile name
            std::string severity = net::derpaul::dicosto::Logger::logSeverityGet();
            REQUIRE(plog::Severity::debug == plog::severityFromString(severity.c_str()));
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test logger custom filename", TestLogger) {
    std::string logFilename = "newlog.log";

    GIVEN("Get fresh logger") {
        THEN("Initialize") {
            loggerReset(net::derpaul::dicosto::defines::LoggerDefaultFilename);
        }

        THEN("Check default logger filename") {
            // Read default logfile name
            std::string loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }

        WHEN("Init with different filename") {
            // Init with different logfile name, returned name should be equal to argument
            std::string loggerName = net::derpaul::dicosto::Logger::logInit(logFilename);
            REQUIRE(logFilename == loggerName);
        }

        WHEN("Init with default filename") {
            // Init with different logfile name, returned name should be equal to argument
            std::string loggerName = net::derpaul::dicosto::Logger::logInit(logFilename);
            REQUIRE(logFilename == loggerName);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test logger set/get of filename", TestLogger) {
    GIVEN("Get fresh logger") {
        THEN("Initialize") {
            loggerReset(net::derpaul::dicosto::defines::LoggerDefaultFilename);
        }

        THEN("Check default logger filename") {
            // Read default logfile name
            std::string loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }

        WHEN("Use default Init") {
            // Logfile name of init should be equal to default
            std::string loggerName = net::derpaul::dicosto::Logger::logInit();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }

        WHEN("Rename logfile") {
            // Set different logfile name
            std::string logFilename = "newlog.log";
            std::string loggerName = net::derpaul::dicosto::Logger::logFilenameSet(logFilename);
            REQUIRE(logFilename == loggerName);
            loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
            REQUIRE(logFilename == loggerName);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test log file created", TestLogger) {
    const std::string sut = "log message";

    GIVEN("Get fresh logger") {
        THEN("Initialize") {
            loggerReset(net::derpaul::dicosto::defines::LoggerDefaultFilename);
        }

        THEN("Check default logger filename") {
            // Read default logfile name
            std::string loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }

        WHEN("Check logfile existence") {
            // No logfile should exist
            REQUIRE(false == file_exists(net::derpaul::dicosto::defines::LoggerDefaultFilename));
            // Logfile name of init should be equal to default
            std::string loggerName = net::derpaul::dicosto::Logger::logInit();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
            // Write a message to logfile
            PLOGD << sut;
            // Now a logfile exist
            REQUIRE(true == file_exists(net::derpaul::dicosto::defines::LoggerDefaultFilename));
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test log message", TestLogger) {
    const std::string logmsg = "log message";
    std::string line = "";
    bool found = false;
    int linecount = 0;

    GIVEN("Get fresh logger") {
        THEN("Initialize") {
            loggerReset(net::derpaul::dicosto::defines::LoggerDefaultFilename);
        }

        THEN("Check default logger filename") {
            // Read default logfile name
            std::string loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
        }

        WHEN("Check logfile content") {
            // No logfile should exist
            REQUIRE(false == file_exists(net::derpaul::dicosto::defines::LoggerDefaultFilename));
            // Logfile name of init should be equal to default
            std::string loggerName = net::derpaul::dicosto::Logger::logInit();
            REQUIRE(net::derpaul::dicosto::defines::LoggerDefaultFilename == loggerName);
            // Write a message to logfile
            PLOGD << logmsg;
            // Now a logfile should exist
            REQUIRE(true == file_exists(net::derpaul::dicosto::defines::LoggerDefaultFilename));
            // Check content of logfile
            std::ifstream infile(net::derpaul::dicosto::defines::LoggerDefaultFilename.c_str());
            // Read line by line
            while (std::getline(infile, line)) {
                // Count the lines
                linecount++;
                // Check line contains message written to log
                if (line.find(logmsg) != std::string::npos) {
                    found = true;
                }
            }
            // Message should be found
            REQUIRE(true == found);
            // Wrote only one line to log, check here
            REQUIRE(1 == linecount);
        }
    }
}
