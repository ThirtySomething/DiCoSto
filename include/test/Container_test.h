#pragma once

#include <catch2/catch.hpp>

#include "../Container.h"
#include "../Defines.h"
#include "TestHelper.h"


// *****************************************************************************
// *****************************************************************************
// Group name of all tests here
static const char groupContainer[] = "[Container]";

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test container get default name", groupContainer) {
    GIVEN("Get fresh container") {
        THEN("Cleanup") {
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
        }

        THEN("Check default container name") {
            net::derpaul::dicosto::Container sut;
            std::string containerName = sut.containerNameGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultName == containerName);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test default container size", groupContainer) {
    GIVEN("Get fresh container") {
        THEN("Cleanup") {
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
        }

        THEN("Check default container size") {
            net::derpaul::dicosto::Container sut;
            unsigned long containerSize = sut.containerSizeGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultContainerSize == containerSize);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test change container size", groupContainer) {
    GIVEN("Get fresh container") {
        net::derpaul::dicosto::Container sut;

        THEN("Cleanup") {
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
        }

        THEN("Check default container size") {
            unsigned long containerSize = sut.containerSizeGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultContainerSize == containerSize);
        }

        WHEN("Check new size smaller than current size") {
            unsigned long containerSizeNew = net::derpaul::dicosto::Defines::ContainerDefaultContainerSize / 2;
            sut.containerSizeSet(containerSizeNew);
            unsigned long containerSize = sut.containerSizeGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultContainerSize == containerSize);
        }

        WHEN("Check new size equal than current size") {
            unsigned long containerSizeNew = net::derpaul::dicosto::Defines::ContainerDefaultContainerSize;
            sut.containerSizeSet(containerSizeNew);
            unsigned long containerSize = sut.containerSizeGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultContainerSize == containerSize);
        }

        WHEN("Check new size greater than current size") {
            unsigned long containerSizeNew = net::derpaul::dicosto::Defines::ContainerDefaultContainerSize * 2;
            sut.containerSizeSet(containerSizeNew);
            unsigned long containerSize = sut.containerSizeGet();
            REQUIRE(containerSizeNew == containerSize);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test create container", groupContainer) {
    GIVEN("Get fresh container") {
        net::derpaul::dicosto::Container sut;

        THEN("Cleanup") {
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
        }

        THEN("Check container is not existing") {
            bool containerExist = file_exists(net::derpaul::dicosto::Defines::ContainerDefaultName);
            REQUIRE(false == containerExist);
        }

        WHEN("Check container exists") {
            bool initSuccess = sut.containerInit();
            REQUIRE(true == initSuccess);
            bool containerExist = file_exists(net::derpaul::dicosto::Defines::ContainerDefaultName);
            REQUIRE(true == containerExist);
        }

        THEN("Cleanup") {
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test rename container unmounted", groupContainer) {
    const std::string containerNameNew = "container.dta";

    GIVEN("Get fresh container") {
        net::derpaul::dicosto::Container sut;

        THEN("Cleanup") {
            removefile(containerNameNew);
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
        }

        WHEN("Check container default name") {
            std::string containerNameOld = sut.containerNameGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultName == containerNameOld);
        }

        THEN("Check container is not mounted") {
            // Container is unmounted by default
            bool mountStatus = sut.containerIsMounted();
            REQUIRE(false == mountStatus);
        }

        THEN("Check container rename") {
            bool successfulRename = sut.containerRename(containerNameNew);
            std::string containerName = sut.containerNameGet();
            REQUIRE(true == successfulRename);
            REQUIRE(containerNameNew != net::derpaul::dicosto::Defines::ContainerDefaultName);
            REQUIRE(containerName == containerNameNew);
        }
    }
}

// *****************************************************************************
// *****************************************************************************
SCENARIO("Test rename container mounted", groupContainer) {
    const std::string containerNameNew = "container.dta";
    std::string containerName;
    bool mountStatus;
    net::derpaul::dicosto::Container sut;

    GIVEN("Get fresh container") {
        THEN("Cleanup") {
            removefile(net::derpaul::dicosto::Defines::ContainerDefaultName);
            removefile(containerNameNew);
        }

        WHEN("Check container default name") {
            containerName = sut.containerNameGet();
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultName == containerName);
        }

        THEN("Check container is not mounted") {
            // Container is unmounted by default
            mountStatus = sut.containerIsMounted();
            REQUIRE(false == mountStatus);
        }

        THEN("Check init of container") {
            // Init container
            bool initDone = sut.containerInit();
            REQUIRE(true == initDone);
        }

        THEN("Check mount of container") {
            // Mount container
            mountStatus = sut.containerMount();
            REQUIRE(true == mountStatus);
        }

        THEN("Check rename of mounted container") {
            // Mount container
            mountStatus = sut.containerMount();
            REQUIRE(true == mountStatus);
            bool renameSuccess = sut.containerRename(containerNameNew);
            REQUIRE(false == renameSuccess);
            // Because of mount status this should not work
            containerName = sut.containerNameGet();
            REQUIRE(containerNameNew != containerName);
            REQUIRE(net::derpaul::dicosto::Defines::ContainerDefaultName == containerName);
        }
    }
}
