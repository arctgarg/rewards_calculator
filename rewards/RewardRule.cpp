//
// Created by agarg145 on 2/16/20.
//

#include "RewardRule.h"

#include <iostream>

const string &RewardRule::getMerchantType() const {
    return merchantType;
}

void RewardRule::setMerchantType(const string &merchantType) {
    RewardRule::merchantType = merchantType;
}

const string &RewardRule::getTransactionType() const {
    return transactionType;
}

void RewardRule::setTransactionType(const string &transactionType) {
    RewardRule::transactionType = transactionType;
}

float RewardRule::getLowerTransactionAmountLimit() const {
    return lowerTransactionAmountLimit;
}

void RewardRule::setLowerTransactionAmountLimit(float lowerTransactionAmountLimit) {
    RewardRule::lowerTransactionAmountLimit = lowerTransactionAmountLimit;
}

float RewardRule::getUpperTransactionAmountLimit() const {
    return upperTransactionAmountLimit;
}

void RewardRule::setUpperTransactionAmountLimit(float upperTransactionAmountLimit) {
    RewardRule::upperTransactionAmountLimit = upperTransactionAmountLimit;
}

float RewardRule::getRewardValue() const {
    return rewardValue;
}

void RewardRule::setRewardValue(float rewardValue) {
    RewardRule::rewardValue = rewardValue;
}

const string &RewardRule::getRuleType() const {
    return ruleType;
}

void RewardRule::setRuleType(const string &ruleType) {
    RewardRule::ruleType = ruleType;
}

int RewardRule::getRewardPoints(const Transaction &transaction) {
    if(this->getRuleType() == "percent")
        return transaction.getTransactionAmount()*this->getRewardValue()/100;
    else return this->getRewardValue()*(transaction.getTransactionAmount() < 0 ? -1 : 1);
}

RewardRule::RewardRule(std::vector<string> row) {
    this->setLowerTransactionAmountLimit(stof(row[1]));
    this->setUpperTransactionAmountLimit(stof(row[2]));
    this->setTransactionType(row[3]);
    this->setMerchantType(row[4]);
    this->setRuleType(row[5]);
    this->setRewardValue(stof(row[6]));
    this->setRuleId(row[0]);
}

RewardRule::RewardRule() {
    this->setRewardValue(0);
}

const string &RewardRule::getRuleId() const {
    return ruleId;
}

void RewardRule::setRuleId(const string &ruleId) {
    RewardRule::ruleId = ruleId;
}
