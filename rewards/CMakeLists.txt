add_library(rewards
        RewardRuleResolver.cpp
        RewardsDbConnector.cpp
        RewardsCalculator.cpp
        RewardRule.cpp)

target_include_directories(rewards PUBLIC .)
target_link_libraries(rewards PUBLIC
        utils
        transactions)

add_subdirectory(test)