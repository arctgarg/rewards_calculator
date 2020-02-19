#include <iostream>
#include <string>
#include <unordered_map>

#include <TransactionsCSVReader.h>
#include <RewardRuleResolver.h>
#include <CSVReader.h>
#include <RewardsDbConnector.h>
#include <RewardsCalculator.h>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

int main(int argc, char** argv) {

    if(argc == 1)
    {
        cout << "Please specify the transactions file as an input" << endl;
        return -1;
    }
    auto transactionsFile = argv[1];

    std::shared_ptr<TransactionReader> transactionReader = std::make_shared<TransactionsCSVReader>(transactionsFile);
    auto ruleReader = RewardRuleCSVReader("/Users/agarg145/CLionProjects/transferwise/rewards/reward_rules.csv");
    std::shared_ptr<RewardRuleResolver> ruleResolver = std::make_shared<RewardRuleResolver>(ruleReader.readRules());
    RewardsCalculator rewardsCalculator(transactionReader, ruleResolver);
    rewardsCalculator.calculate();

    return 0;
}