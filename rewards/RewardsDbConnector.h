//
// Created by agarg145 on 2/18/20.
//

#ifndef TRANSFERWISE_REWARDSDBCONNECTOR_H
#define TRANSFERWISE_REWARDSDBCONNECTOR_H

#include <string>
#include <jdbc/cppconn/connection.h>

using std::string;

struct ClientRewardPoints{
    string clientId;
    string clientName;
    int rewardPoints;
};

class RewardsDbConnector {
public:
    RewardsDbConnector(string hostname, string username, string password);

    ~RewardsDbConnector();

    int getClientRewardPoints(string clientId);

    bool addClientRewardPoints(string clientId, string clientName, int rewardPoints);

    bool updateClientRewardPoints(string clientId, int rewardPoints);

    std::vector<ClientRewardPoints> getAllClientRewardPointsData();

private:
    sql::Connection* d_connectionPtr;
};


#endif //TRANSFERWISE_REWARDSDBCONNECTOR_H
