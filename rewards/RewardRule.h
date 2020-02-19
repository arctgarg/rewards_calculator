//
// Created by agarg145 on 2/16/20.
//

#ifndef TRANSFERWISE_REWARDRULE_H
#define TRANSFERWISE_REWARDRULE_H

#include <string>
#include <transaction.h>

class RewardRule {
    string ruleId;
public:
    const string &getRuleId() const;

    void setRuleId(const string &ruleId);

private:
    std::string merchantType;
    std::string transactionType;
    float lowerTransactionAmountLimit;
    float upperTransactionAmountLimit;
    float rewardValue;
public:
    const string &getMerchantType() const;

    void setMerchantType(const string &merchantType);

    const string &getTransactionType() const;

    void setTransactionType(const string &transactionType);

    float getLowerTransactionAmountLimit() const;

    void setLowerTransactionAmountLimit(float lowerTransactionAmountLimit);

    float getUpperTransactionAmountLimit() const;

    void setUpperTransactionAmountLimit(float upperTransactionAmountLimit);

    float getRewardValue() const;

    void setRewardValue(float rewardValue);

    const string &getRuleType() const;

    void setRuleType(const string &ruleType);

    int getRewardPoints(const Transaction& transaction);

    explicit RewardRule(std::vector<string> row);

    RewardRule();
private:
    string ruleType;
public:

};


#endif //TRANSFERWISE_REWARDRULE_H
