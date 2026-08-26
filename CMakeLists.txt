cmake_minimum_required(VERSION 3.20)

project(fuzzerd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# disable tests for dependencies
set(CPR_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(JSON_BuildTests OFF CACHE BOOL "" FORCE)
# disable libpsl for libcurl
set(CPR_CURL_USE_LIBPSL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/cpr)
add_subdirectory(external/json)

add_executable(fuzzerd)

target_sources(fuzzerd
    PRIVATE
    main.cpp
)

target_link_libraries(fuzzerd
    PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
)
