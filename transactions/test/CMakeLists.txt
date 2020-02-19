add_executable(transactions_test
        TransactionsCSVReaderTest.cpp)

target_link_libraries(transactions_test PUBLIC
        gtest_main
        gmock
        transactions)

add_test(
        NAME transactions_test
        COMMAND transactions_test
)