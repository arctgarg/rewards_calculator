//
// Created by agarg145 on 2/20/20.
//

#include <unordered_map>
#include "RewardsCalculator.h"
#include "RewardRuleResolver.h"

using std::unordered_map;
using std::string;
using std::cout;
using std::endl;

RewardsCalculator::RewardsCalculator(std::shared_ptr<TransactionReader> transactionReader,
                                     std::shared_ptr<RewardRuleResolver> ptr) : d_transactionReader(transactionReader), d_rewardRuleResolver(ptr){
    d_rewardsDb.init();
}

void RewardsCalculator::calculate() {
    while(true)
    {
        auto transactions = d_transactionReader->getNextTransactions(1000);
        if(transactions.size() == 0) break;

        for(auto transaction : transactions)
        {
            auto rule = d_rewardRuleResolver->findApplicableRule(transaction);
            auto rewardPoints = rule.getRewardPoints(transaction);
            auto previousRewardPoints = d_rewardsDb.getClientRewardPoints(transaction.getCustomerId());
            if(previousRewardPoints < 0)
            {
                d_rewardsDb.addClientRewardPoints(transaction.getCustomerId(), transaction.getCustomerName(), std::max(0, rewardPoints));
                continue;
            }
            auto newRewardPoints = std::max(previousRewardPoints + rewardPoints, 0);
            d_rewardsDb.updateClientRewardPoints(transaction.getCustomerId(), newRewardPoints);
        }
    }

    auto clientRewardData = d_rewardsDb.getAllClientRewardPointsData();
    for(auto& clientData : clientRewardData)
    {
        cout << "clientId :" << clientData.clientId << " client name :" << clientData.clientName << " reward points :" << clientData.rewardPoints << endl;
    }
}
