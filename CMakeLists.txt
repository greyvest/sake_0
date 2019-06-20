cmake_minimum_required (VERSION 2.6)
project (Sake)

#Version Numbers
set (Sake_VERSION_MAJOR 0)
set (Sake_VERSION_MINOR 1)

#configure header file to pass some of the cmake settings to source code
configure_file(
    "$(PROJECT_SOURCE_DIR)/TutorialConfig.h.in"
    "$(PROJECT_BINARY_DIR)/TutorialConfig.h"
)

# add the executable 
add_executable(Sake src/main.cpp)

