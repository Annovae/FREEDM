cmake_minimum_required(VERSION 2.6)

project(Broker)

# Support build versioning for development builds
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)

# ${GIT_SHA1} for development builds. Set to an appropriate string for releases.
set(BROKER_VERSION ${GIT_SHA1})

# Options go here; be sure to edit config.hpp.cmake if they're needed for build
option(CUSTOMNETWORK "for network.xml support" OFF)
option(DATAGRAM "for UDP Datagram service w/o sequencing" OFF)
option(DOXYGEN "run Doxygen after project compile" ON)
option(TRACK_HANDLERS "enable Boost.Asio handler tracking" OFF)
option(WARNINGS "warnings displayed during project compile" ON)

# Boost
find_package(Boost 1.47 REQUIRED
             COMPONENTS date_time program_options system thread
            )
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# set C++ compiler flags
if(WARNINGS)
    set(WARNING_FLAGS "-Wall -Wextra")
else()
    set(WARNING_FLAGS "-w")
endif()

# Use -DCMAKE_BUILD_TYPE to control optimization and debugging
set(CMAKE_CXX_FLAGS
    "-pedantic -pthread -std=c++98 ${WARNING_FLAGS} ${CMAKE_CXX_FLAGS}")

if(TRACK_HANDLERS)
    add_definitions(-DBOOST_ASIO_ENABLE_HANDLER_TRACKING)
endif()

# include project source directories
# probably would be better to require source files to use relative paths...
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_BINARY_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/src/device")
include_directories("${PROJECT_BINARY_DIR}/src/device")

# goto src/CMakeLists.txt
add_subdirectory(src)

add_executable(PosixBroker src/PosixMain.cpp)

# link the executable to its dependencies
target_link_libraries(PosixBroker
                      broker
                      device
                      ${Boost_DATE_TIME_LIBRARY}
                      ${Boost_PROGRAM_OPTIONS_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_THREAD_LIBRARY}
                     )

if(DOXYGEN)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        add_custom_command(TARGET PosixBroker POST_BUILD
                           COMMAND doxygen ${PROJECT_SOURCE_DIR}/freedm.dxy
                          )
    endif()
endif()
