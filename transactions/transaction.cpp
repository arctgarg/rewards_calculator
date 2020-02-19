//
// Created by agarg145 on 2/16/20.
//

#include "transaction.h"
#include <iostream>

const string &Transaction::getTransactionId() const {
    return transactionId;
}

void Transaction::setTransactionId(const string &transactionId) {
    Transaction::transactionId = transactionId;
}

const string &Transaction::getCustomerId() const {
    return customerId;
}

void Transaction::setCustomerId(const string &customerId) {
    Transaction::customerId = customerId;
}

const string &Transaction::getCustomerName() const {
    return customerName;
}

void Transaction::setCustomerName(const string &customerName) {
    Transaction::customerName = customerName;
}

const string &Transaction::getBankName() const {
    return bankName;
}

void Transaction::setBankName(const string &bankName) {
    Transaction::bankName = bankName;
}

float Transaction::getTransactionAmount() const {
    return transactionAmount;
}

void Transaction::setTransactionAmount(float transactionAmount) {
    Transaction::transactionAmount = transactionAmount;
}

const string &Transaction::getMerchantName() const {
    return merchantName;
}

void Transaction::setMerchantName(const string &merchantName) {
    Transaction::merchantName = merchantName;
}

const string &Transaction::getMerchantType() const {
    return merchantType;
}

void Transaction::setMerchantType(const string &merchantType) {
    Transaction::merchantType = merchantType;
}

const string &Transaction::getCountry() const {
    return country;
}

void Transaction::setCountry(const string &country) {
    Transaction::country = country;
}

const string &Transaction::getTransactionType() const {
    return transactionType;
}

void Transaction::setTransactionType(const string &transactionType) {
    Transaction::transactionType = transactionType;
}

void Transaction::print() {
    std::cout << "Transaction :" << this->getTransactionId() << std::endl;
}
