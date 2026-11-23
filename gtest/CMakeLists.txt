find_package(Threads REQUIRED)

add_library(gtest STATIC src/gtest-all.cc)

target_include_directories(gtest
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include   # <gtest/gtest.h>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})          # "src/gtest.cc" внутри gtest-all.cc

target_link_libraries(gtest PUBLIC Threads::Threads)
