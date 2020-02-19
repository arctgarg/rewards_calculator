add_library(transactions
        transaction.cpp
        TransactionsCSVReader.cpp)

target_include_directories(transactions PUBLIC .)
target_link_libraries(transactions PUBLIC
        utils)

add_subdirectory(test)