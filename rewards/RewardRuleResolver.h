//
// Created by agarg145 on 2/16/20.
//

#ifndef TRANSFERWISE_REWARDRULERESOLVER_H
#define TRANSFERWISE_REWARDRULERESOLVER_H


#include <transaction.h>
#include <CSVReader.h>
#include "RewardRule.h"

using std::vector;

class RewardRuleReader {
    virtual std::vector<RewardRule> readRules() = 0;
};

class RewardRuleCSVReader : public RewardRuleReader, CSVReader{
public:
    explicit RewardRuleCSVReader(std::string filepath);
    std::vector<RewardRule> readRules() override;
};

class RewardRuleResolver {
public:
    RewardRuleResolver(vector<RewardRule> rewardRules);

    RewardRule findApplicableRule(const Transaction& transaction);

private:
    std::vector<RewardRule> rules;
    int getMatchingParametersCount(const RewardRule& rule, const Transaction transaction);
};


#endif //TRANSFERWISE_REWARDRULERESOLVER_H
