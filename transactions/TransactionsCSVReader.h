//
// Created by agarg145 on 2/16/20.
//

#ifndef TRANSFERWISE_TRANSACTIONSCSVREADER_H
#define TRANSFERWISE_TRANSACTIONSCSVREADER_H

#include "transaction.h"
#include <CSVReader.h>

using std::vector;

class TransactionReader {
public:
    virtual vector<Transaction> getNextTransactions(int numberOfTransactions) = 0;
};

class TransactionsCSVReader : public TransactionReader, CSVReader{
public:
    TransactionsCSVReader(std::string filepath);

    vector<Transaction> getNextTransactions(int numberOfTransactions) override;

protected:
    static  std::vector<Transaction> parseTransactionRows(std::vector<std::vector<std::string>> vector);
};


#endif //TRANSFERWISE_TRANSACTIONSCSVREADER_H
