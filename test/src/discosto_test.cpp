#define CATCH_CONFIG_MAIN

#ifdef CATCH_CONFIG_MAIN

#include "Block_test.h"
#include "Container_test.h"
#include "Logger_test.h"

#else

#include <iostream>
#include "Defines.h"
#include "Block.h"

int main(void) {
    net::derpaul::dicosto::ContainerData data(1024, 0);
    net::derpaul::dicosto::BlockAddress pos = 0L;
    char val = net::derpaul::dicosto::Block::getByte1(data, pos);

    if (0 == val) {
        std::cout << "OK!" << std::endl;
    }
    else {
        std::cout << "FAIL!" << std::endl;
    }

    return 0;
}

#endif
