cmake_minimum_required(VERSION 3.15)
project(transferwise)

set(CMAKE_CXX_STANDARD 14)
set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /usr/local/mysql-connector-c++-8.0.18)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64)
set(CMAKE_INSTALL_RPATH ${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64)
set(INSTALL_RPATH_USE_LINK_PATH ON)
set(CMAKE_MACOSX_RPATH OFF)

enable_testing()

add_subdirectory(rewards)
add_subdirectory(transactions)
add_subdirectory(utils)
add_subdirectory(external_libs)

add_executable(transferwise main.cpp)

target_link_libraries(transferwise
        mysqlcppconn-static
        crypto.1.1
        ssl
        transactions
        utils
        rewards
        )

