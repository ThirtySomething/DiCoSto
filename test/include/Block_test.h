#pragma once

#include <catch2/catch.hpp>
#include "Defines.h"
#include "Block.h"

// *****************************************************************************
// *****************************************************************************
// Group name of all tests here
static const char TestBlock[] = "[Block]";

net::derpaul::dicosto::defines::BlockAddress posFirst = 0L;
net::derpaul::dicosto::defines::BlockAddress posSecond = 16L;
unsigned char initValue = 0x00;

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test block one byte", TestBlock) {
    GIVEN("Get fresh block") {
        net::derpaul::dicosto::defines::ContainerData data(1024, initValue);

        WHEN("Check get/set") {
            net::derpaul::dicosto::defines::BlockAddress pos = posFirst;
            unsigned char result = net::derpaul::dicosto::Block::getBytes1(data, pos);
            REQUIRE(initValue == result);

            unsigned char val = 0xFF;
            net::derpaul::dicosto::Block::setBytes1(data, pos, val);

            result = net::derpaul::dicosto::Block::getBytes1(data, pos);
            REQUIRE(val == result);

            pos = posSecond;
            result = net::derpaul::dicosto::Block::getBytes1(data, pos);
            REQUIRE(initValue == result);

            net::derpaul::dicosto::Block::setBytes1(data, pos, val);

            result = net::derpaul::dicosto::Block::getBytes1(data, pos);
            REQUIRE(val == result);
        }
    }
}
