#pragma once

#include <catch2/catch.hpp>
#include "../Logger.h"
#include "../Defines.h"

void loggerReset(void) {
    net::derpaul::dicosto::Logger::logFilenameSet(DICOSTO_LOGGER_DEFAULT_FILENAME);
}

SCENARIO("Test logger default filename", "[Logger]") {
    loggerReset();

    DICOSTO_STR loggerName = net::derpaul::dicosto::Logger::logInit();
    REQUIRE(DICOSTO_LOGGER_DEFAULT_FILENAME == loggerName);
}

SCENARIO("Test logger custom filename", "[Logger]") {
    DICOSTO_STR sut = "testme.log";

    loggerReset();

    DICOSTO_STR loggerName = net::derpaul::dicosto::Logger::logInit(sut);
    REQUIRE(sut == loggerName);
}

SCENARIO("Test logger set/get of filename", "[Logger]") {
    DICOSTO_STR sut = "testme.log";

    loggerReset();

    DICOSTO_STR loggerName = net::derpaul::dicosto::Logger::logInit();
    REQUIRE(DICOSTO_LOGGER_DEFAULT_FILENAME == loggerName);

    loggerName = net::derpaul::dicosto::Logger::logFilenameSet(sut);
    REQUIRE(sut == loggerName);

    loggerName = net::derpaul::dicosto::Logger::logFilenameGet();
    REQUIRE(sut == loggerName);
}
