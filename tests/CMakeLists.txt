add_executable(run_tests
    test_main.cpp
    test_queue.cpp
    ${PROJECT_SOURCE_DIR}/queue/tqueue.h)   # чтобы заголовок был виден в IDE

target_include_directories(run_tests PRIVATE ${PROJECT_SOURCE_DIR}/queue)
target_link_libraries(run_tests PRIVATE gtest)


