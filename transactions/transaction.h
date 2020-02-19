//
// Created by agarg145 on 2/16/20.
//

#ifndef TRANSFERWISE_TRANSACTION_H
#define TRANSFERWISE_TRANSACTION_H

#include <string>
#include <vector>

using std::string;

class Transaction {

private:
    string customerId;
    string customerName;
    string bankName;
    float transactionAmount;
    string merchantName;
    string merchantType;
    string country;
    string transactionType;
    string transactionId;

public:

    void print();

    const string &getTransactionId() const;

    void setTransactionId(const string &transactionId);

    const string &getCustomerId() const;

    void setCustomerId(const string &customerId);

    const string &getCustomerName() const;

    void setCustomerName(const string &customerName);

    const string &getBankName() const;

    void setBankName(const string &bankName);

    float getTransactionAmount() const;

    void setTransactionAmount(float transactionAmount);

    const string &getMerchantName() const;

    void setMerchantName(const string &merchantName);

    const string &getMerchantType() const;

    void setMerchantType(const string &merchantType);

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getTransactionType() const;

    void setTransactionType(const string &transactionType);
};


#endif //TRANSFERWISE_TRANSACTION_H
