//
// Created by agarg145 on 2/18/20.
//

#include "RewardsDbConnector.h"

#include <mysql/jdbc.h>
#include <vector>

using std::string;
using std::cout;
using std::endl;

void RewardsDbConnector::init() {
    auto driver = sql::mysql::get_driver_instance();
    string host  = "localhost";
    string username = "root";
    string password = "root";
    d_connectionPtr = driver->connect(host, username, password);
    cout << "  connection status " << d_connectionPtr->isValid() << endl;
    d_connectionPtr->setSchema("rewards");
}

int RewardsDbConnector::getClientRewardPoints(string clientId) {
    auto statement = d_connectionPtr->prepareStatement("select reward_points from client_rewards where client_id = ?");
    statement->setString(1, clientId);
    auto result = statement->executeQuery();
    while(result->next())
    {
        return result->getInt("reward_points");
    }
    return -1;
}

bool RewardsDbConnector::addClientRewardPoints(string clientId, string clientName, int rewardPoints) {
    auto statement = d_connectionPtr->prepareStatement("insert into client_rewards VALUES(?, ?, ?)");
    statement->setString(1, clientId);
    statement->setString(2, clientName);
    statement->setInt(3, rewardPoints);
    return statement->execute();
}

bool RewardsDbConnector::updateClientRewardPoints(string clientId, int rewardPoints) {
    auto statement = d_connectionPtr->prepareStatement("update client_rewards set reward_points = ? where client_id = ?");
    statement->setInt(1, rewardPoints);
    statement->setString(2, clientId);
    return statement->executeUpdate() == 0;
}

std::vector<ClientRewardPoints> RewardsDbConnector::getAllClientRewardPointsData() {
    std::vector<ClientRewardPoints> clientRewardPointsVector;
    auto statement = d_connectionPtr->prepareStatement("select * from client_rewards");
    auto result = statement->executeQuery();
    while(result->next())
    {
        ClientRewardPoints clientRewardPoints;
        clientRewardPoints.clientId = result->getString("client_id");
        clientRewardPoints.clientName = result->getString("client_name");
        clientRewardPoints.rewardPoints = result->getInt("reward_points");
        clientRewardPointsVector.push_back(clientRewardPoints);
    }
    return clientRewardPointsVector;
}

RewardsDbConnector::~RewardsDbConnector() {
    d_connectionPtr->close();
}
