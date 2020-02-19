add_executable(utils_test
        CSVReaderTest.cpp)

target_link_libraries(utils_test PUBLIC
        gtest_main
        utils)

add_test(
        NAME utils_test
        COMMAND utils_test
)