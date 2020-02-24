add_library(rewards
        RewardRuleResolver.cpp
        RewardsDbConnector.cpp
        RewardsCalculator.cpp
        RewardRule.cpp)

target_include_directories(rewards PUBLIC .)
target_link_libraries(rewards PUBLIC
        utils
	mysqlcppconn
        transactions)

add_subdirectory(test)
