//
// Created by agarg145 on 2/19/20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <TransactionsCSVReader.h>

using std::string;
using ::testing::Return;

class MockTransactionsCSVReader : public TransactionsCSVReader
{
public:
    MockTransactionsCSVReader(std::string filepath) : TransactionsCSVReader(filepath) {
    }
    MOCK_METHOD(std::vector<std::vector<std::string> > , getNextRecords, (int numberOfRecords));
};

class TransactionsCSVReaderTest : public ::testing::Test
{
protected:
    std::vector<string> d_transaction1{"id1","f411d086-85fd-4904-8c33-e32a008abf0a","Jane Doe","Archaic Big Bank","12.2","McDonalds","Fast Food","Germany","CHIP AND PIN"};
    std::vector<string> d_transaction2{"id2","a234509b-88a9-4451-9d92-21d8475e8def","John Smith","Shady Bank","2.5","Starbucks","Fast Food","Latvia","CONTACTLESS"};
};

TEST_F(TransactionsCSVReaderTest, testReadCSV)
{
    MockTransactionsCSVReader reader("");

    vector<vector<string>> transactions{d_transaction1, d_transaction2};
    EXPECT_CALL(reader, getNextRecords(1000)).Times(1).WillOnce(Return(transactions));
    auto result = reader.getNextTransactions(1000);
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ( result[0].getTransactionId(), d_transaction1[0]);
    ASSERT_EQ( result[1].getTransactionId(), d_transaction2[0]);
}

