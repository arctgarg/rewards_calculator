//
// Created by agarg145 on 2/20/20.
//

#ifndef TRANSFERWISE_REWARDSCALCULATOR_H
#define TRANSFERWISE_REWARDSCALCULATOR_H


#include <TransactionsCSVReader.h>
#include "RewardRuleResolver.h"
#include "RewardsDbConnector.h"

class RewardsCalculator {
    std::shared_ptr<TransactionReader> d_transactionReader;
    std::shared_ptr<RewardRuleResolver> d_rewardRuleResolver;
    std::shared_ptr<RewardsDbConnector> d_rewardsDbConnector;
public:
    explicit RewardsCalculator(std::shared_ptr<TransactionReader> transactionReader,
                               std::shared_ptr<RewardRuleResolver> ptr, std::shared_ptr<RewardsDbConnector> dbConnectorPtr);

    void calculate();
};


#endif //TRANSFERWISE_REWARDSCALCULATOR_H
