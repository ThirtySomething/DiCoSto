#include "TestHelper.h"
#include <sys/stat.h>
#include <cstdio>
#include "Logger.h"

// *****************************************************************************
// Check file for existence of file
// *****************************************************************************
bool file_exists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

// *****************************************************************************
// Remove file if exists
// *****************************************************************************
int removefile(const std::string& name) {
    int delStat = 0;
    if (file_exists(name.c_str())) {
        delStat = remove(name.c_str());
    }
    return delStat;
}

// *****************************************************************************
// Reset logger and remove default logfile
// *****************************************************************************
void loggerReset(const std::string& name) {
    std::string logfileOld = net::derpaul::dicosto::Logger::logFilenameGet();
    net::derpaul::dicosto::Logger::logFilenameSet(name);
    net::derpaul::dicosto::Logger::logStop();
    removefile(logfileOld);
    net::derpaul::dicosto::Logger::logInit();
}
