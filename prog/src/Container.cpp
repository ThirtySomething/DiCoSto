#include "Container.h"

#include <sys/stat.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include "Defines.h"
#include "Logger.h"
#include <exception>

namespace net {
    namespace derpaul {
        namespace dicosto {
            // *****************************************************************************
            // *****************************************************************************
            Container::Container(const std::string& containerName) : isMounted{ false }, containerName{ containerName }, containerSize{ defines::ContainerDefaultContainerSize } {
            }

            // *****************************************************************************
            // *****************************************************************************
            Container::Container(void) : isMounted{ false }, containerName{ defines::ContainerDefaultName }, containerSize{ defines::ContainerDefaultContainerSize } {
            }

            // *****************************************************************************
            // *****************************************************************************
            Container::~Container(void) {
                this->containerUnmount();
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerCreate(void) {
                // Create an empty file filled with zeros, see also
                // https://stackoverflow.com/questions/7896035/c-make-a-file-of-a-specific-size
                std::vector<char> empty(defines::ContainerDefaultBlockSize, 0);
                std::ofstream ofs(this->containerNameGet(), std::ios::binary | std::ios::out);

                for (unsigned long i = 0; i < defines::ContainerDefaultBlockSize * this->containerSizeGet(); i++)
                {
                    if (!ofs.write(&empty[0], empty.size()))
                    {
                        PLOGE << "Creation of container [" << this->containerNameGet() << "] failed.";
                        return false;
                    }
                }
                PLOGI << "Creation of container [" << this->containerNameGet() << "] successful.";
                return true;
            }

            // *****************************************************************************
            // *****************************************************************************
            const bool Container::containerExist(void) const {
                struct stat buffer;
                return (stat(this->containerNameGet().c_str(), &buffer) == 0);
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerInit(void) {
                bool success = this->containerExist();

                if (!success) {
                    success = this->containerCreate();
                }

                return success;
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerMount(void) {
                if (this->containerExist() && !this->containerIsMounted() && !containerfile.is_open()) {
                    try {
                        containerfile.open(this->containerNameGet(), std::ios::in | std::ios::binary);
                        if (containerfile.is_open()) {
                            PLOGI << "Container [" << this->containerNameGet() << "] mounted";
                            this->isMounted = true;
                        }
                        else {
                            PLOGF << "Container [" << this->containerNameGet() << "] mount failed";
                        }
                    }
                    catch (const std::exception& e) {
                        PLOGF << "Open container [" << this->containerNameGet() << "] failed: " << e.what();
                    }
                }
                return this->containerIsMounted();
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerIsMounted(void) {
                return this->isMounted;
            }

            // *****************************************************************************
            // *****************************************************************************
            std::string Container::containerNameGet(void) const {
                return this->containerName;
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerRename(const std::string& containerName) {
                if (!this->containerExist()) {
                    // No file, just rename
                    this->containerName = containerName;
                    return true;
                }

                if (this->containerIsMounted()) {
                    // No rename if mounted
                    PLOGI << "Cannot rename mounted container [" << this->containerNameGet() << "]";
                    return false;
                }

                // Asumption: Rename not successful
                bool result = false;
                int tmpval = rename(this->containerName.c_str(), containerName.c_str());
                if (0 == tmpval) {
                    // Rename of file successful, change container name
                    result = true;
                    PLOGI << "Container renamed from [" << this->containerNameGet() << "] to [" << containerName << "]";
                    this->containerName = containerName;
                }

                return result;
            }

            // *****************************************************************************
            // *****************************************************************************
            unsigned long long Container::containerSizeGet(void) const {
                return this->containerSize;
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerSizeSet(const unsigned long long& containerSize) {
                bool result = false;
                if (this->containerSizeGet() > containerSize) {
                    PLOGE << "New container size [" << containerSize << "] smaller than current container size [" << this->containerSizeGet() << "]";
                    result = false;
                }
                else if (this->containerSizeGet() == containerSize) {
                    PLOGI << "New container size [" << this->containerSizeGet() << "] equal to current size, not changed.";
                    result = true;
                }
                else if (this->containerSizeGet() < containerSize) {
                    PLOGI << "Changed container size from [" << this->containerSizeGet() << "] to [" << containerSize << "]";
                    this->containerSize = containerSize;
                    result = true;
                }
                else {
                    PLOGE << "Invalid container size [" << containerSize << "]";
                    result = false;
                }
                return result;
            }

            // *****************************************************************************
            // *****************************************************************************
            bool Container::containerUnmount(void) {
                if (this->containerExist() && this->containerIsMounted() && containerfile.is_open()) {
                    try {
                        containerfile.close();
                    }
                    catch (const std::exception& e) {
                        PLOGF << "Closing container [" << this->containerNameGet() << "] failed: " << e.what();
                    }
                    PLOGI << "Container [" << this->containerNameGet() << "] unmounted";
                    this->isMounted = false;
                }
                return this->containerIsMounted();
            }

            // *****************************************************************************
            // *****************************************************************************
        }
    }
}
