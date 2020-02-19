//
// Created by agarg145 on 2/16/20.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "TransactionsCSVReader.h"

std::vector<Transaction> TransactionsCSVReader::parseTransactionRows(std::vector<std::vector<std::string>> inputs) {
    std::vector<Transaction> transactions;
    for(auto input : inputs)
    {
        Transaction transaction;
        transaction.setTransactionId(input[0]);
        transaction.setCustomerId(input[1]);
        transaction.setCustomerName(input[2]);
        transaction.setBankName(input[3]);
        transaction.setTransactionAmount(std::stof(input[4]));
        transaction.setMerchantName(input[5]);
        transaction.setMerchantType(input[6]);
        transaction.setCountry(input[7]);
        transaction.setTransactionType(input[8]);
        transactions.push_back(transaction);
    }
    return transactions;
}

vector<Transaction> TransactionsCSVReader::getNextTransactions(int numberOfTransactions) {
    auto rows = this->getNextRecords(numberOfTransactions);
    return parseTransactionRows(rows);
}

TransactionsCSVReader::TransactionsCSVReader(std::string filepath) : CSVReader(filepath) {
}
