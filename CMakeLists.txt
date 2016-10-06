cmake_minimum_required(VERSION 3.6)
project(settingsmanager_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp SettingsManager.cpp SettingsManager.h)

add_executable(settingsmanager_cpp ${SOURCE_FILES})
target_link_libraries(settingsmanager_cpp boost_system)