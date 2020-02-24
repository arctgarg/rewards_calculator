cmake_minimum_required(VERSION 3.10)
project(transferwise)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(rewards)
add_subdirectory(transactions)
add_subdirectory(utils)
add_subdirectory(external_libs)

add_executable(transferwise main.cpp)

target_link_libraries(transferwise
	mysqlcppconn
        transactions
        utils
        rewards
        )

