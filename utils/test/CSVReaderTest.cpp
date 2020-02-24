//
// Created by agarg145 on 2/19/20.
//

#include <gtest/gtest.h>
#include <CSVReader.h>

using std::string;
using std::cout;
using std::endl;

class CSVReaderTest : public ::testing::Test
{
protected:
    std::vector<string> d_transaction1{"79bb2593-0ccd-4ea6-a409-5b2b67fda997","f411d086-85fd-4904-8c33-e32a008abf0a","Jane Doe","Archaic Big Bank","12.2","McDonalds","Fast Food","Germany","CHIP AND PIN"};
    std::vector<string> d_transaction2{"9bafbebd-d97f-4714-a4a6-021bcc6f61b6","a234509b-88a9-4451-9d92-21d8475e8def","John Smith","Shady Bank","2.5","Starbucks","Fast Food","Latvia","CONTACTLESS"};

};

TEST_F(CSVReaderTest, testReadCSV)
{
    CSVReader csvReader("/home/rewards_calculator/utils/test/transactions_test_data.csv");
    auto result = csvReader.getNextRecords(15);
    cout << "Result size " << result.size() << endl;
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ( result[0], d_transaction1);
    ASSERT_EQ( result[1], d_transaction2);
}

TEST_F(CSVReaderTest, testReadInputMoreThanRecordsInFile)
{
    CSVReader csvReader("/home/rewards_calculator/utils/test/transactions_test_data.csv");
    auto result = csvReader.getNextRecords(15);
    ASSERT_EQ(result.size(), 2);
}

TEST_F(CSVReaderTest, testNoRecordsReturnedIfFileDoesNotExist)
{
    CSVReader csvReader("");
    auto result = csvReader.getNextRecords();
    ASSERT_EQ(result.size(), 0);
}

