//
// Created by agarg145 on 2/16/20.
//

#include "RewardRuleResolver.h"
#include "CSVReader.h"
#include <math.h>
#include <iostream>

using std::vector;

RewardRule RewardRuleResolver::findApplicableRule(const Transaction &transaction) {
    int matchingParamterCount = 0;
    RewardRule matchingRule;
    for(auto rule : this->rules)
    {
        int count = this->getMatchingParametersCount(rule, transaction);
        if(count > matchingParamterCount)
        {
            matchingRule = rule;
            matchingParamterCount = count;
        }
    }
    return matchingRule;
}

RewardRuleResolver::RewardRuleResolver(vector<RewardRule> rules) {
    this->rules = rules;
}

int RewardRuleResolver::getMatchingParametersCount(const RewardRule &rule, const Transaction transaction) {
    int matchingParameterCount = 0;
    if(rule.getTransactionType() != "NULL" ){
        if(rule.getTransactionType() != transaction.getTransactionType())
            return 0;
        else matchingParameterCount++;
    }

    if(rule.getMerchantType() != "NULL"){
        if(rule.getMerchantType() != transaction.getMerchantType())
            return 0;
        else matchingParameterCount++;
    }
    auto absoluteTransactionAmount = abs(transaction.getTransactionAmount());
    if(rule.getUpperTransactionAmountLimit() >= absoluteTransactionAmount) matchingParameterCount++;
    if(rule.getLowerTransactionAmountLimit() <= absoluteTransactionAmount) matchingParameterCount++;
    return matchingParameterCount;
}

std::vector<RewardRule> RewardRuleCSVReader::readRules() {
    auto rows = getNextRecords(1000);
    vector<RewardRule> rules;
    for(auto& row : rows)
    {
        rules.push_back(RewardRule(row));
    }
    return rules;
}

RewardRuleCSVReader::RewardRuleCSVReader(std::string filepath) : CSVReader(filepath) {

}
