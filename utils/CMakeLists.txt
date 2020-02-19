add_library(utils
        CSVReader.cpp)

target_include_directories(utils PUBLIC .)

add_subdirectory(test)