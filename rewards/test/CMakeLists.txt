add_executable(rewards_test
        RewardRuleResolverTest.cpp)

target_link_libraries(rewards_test PUBLIC
        gtest_main
        gmock
        rewards)

add_test(
        NAME rewards_test
        COMMAND rewards_test
)