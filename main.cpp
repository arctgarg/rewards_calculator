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

    if(argc < 5)
    {
        cout << "Please specify the transactions file, db hostname, db username and db password as inputs" << endl;
        return -1;
    }
    auto transactionsFile = argv[1];
    auto dbHostname = argv[2];
    auto dbusername = argv[3];
    auto dbpassword = argv[4];

    std::shared_ptr<TransactionReader> transactionReader = std::make_shared<TransactionsCSVReader>(transactionsFile);
    auto ruleReader = RewardRuleCSVReader("/Users/agarg145/CLionProjects/transferwise/rewards/reward_rules.csv");
    std::shared_ptr<RewardRuleResolver> ruleResolver = std::make_shared<RewardRuleResolver>(ruleReader.readRules());
    std::shared_ptr<RewardsDbConnector> dbConnector = std::make_shared<RewardsDbConnector>(dbHostname, dbusername, dbpassword);
    RewardsCalculator rewardsCalculator(transactionReader, ruleResolver, dbConnector);
    rewardsCalculator.calculate();

    return 0;
}