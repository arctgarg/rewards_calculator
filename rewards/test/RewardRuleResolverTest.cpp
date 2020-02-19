//
// Created by agarg145 on 2/19/20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CSVReader.h>
#include <RewardRuleResolver.h>

using ::testing::Return;
using std::string;
using std::vector;

class RewardRuleResolverTest : public ::testing::Test
{

};

TEST_F(RewardRuleResolverTest, test)
{
    RewardRule rule1({"1","0","2.49","ECOM","NULL","points","0"});
    RewardRule rule2({"2","0","2.49","NULL","NULL","points","1"});
    RewardRule rule3({"3","0","2.49","ECOM","Airlines","points","0"});
    RewardRule rule4({"4","0","2.49","NULL","Airlines","points","2"});
    vector<RewardRule> rules2{rule1, rule2, rule3, rule4};

    RewardRuleResolver ruleResolver(rules2);
    Transaction transaction1;
    transaction1.setMerchantType("something");
    transaction1.setTransactionType("ECOM");
    transaction1.setTransactionAmount(1);

    Transaction transaction2;
    transaction2.setMerchantType("NULL");
    transaction2.setTransactionType("NULL");
    transaction2.setTransactionAmount(1);

    Transaction transaction3;
    transaction3.setMerchantType("Airlines");
    transaction3.setTransactionType("ECOM");
    transaction3.setTransactionAmount(1);

    Transaction transaction4;
    transaction4.setMerchantType("Airlines");
    transaction4.setTransactionType("NULL");
    transaction4.setTransactionAmount(1);

    auto applicableRule1 = ruleResolver.findApplicableRule(transaction1);
    auto applicableRule2 = ruleResolver.findApplicableRule(transaction2);
    auto applicableRule3 = ruleResolver.findApplicableRule(transaction3);
    auto applicableRule4 = ruleResolver.findApplicableRule(transaction4);

    ASSERT_EQ(applicableRule1.getRuleId(), rule1.getRuleId());
    ASSERT_EQ(applicableRule2.getRuleId(), rule2.getRuleId());
    ASSERT_EQ(applicableRule3.getRuleId(), rule3.getRuleId());
    ASSERT_EQ(applicableRule4.getRuleId(), rule4.getRuleId());
}