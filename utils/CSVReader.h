//
// Created by agarg145 on 2/16/20.
//

#ifndef TRANSFERWISE_CSVREADER_H
#define TRANSFERWISE_CSVREADER_H

#include <vector>
#include <string>
#include <memory>
class CSVReader {

public:
    explicit CSVReader(std::string filepath);

    virtual std::vector<std::vector<std::string> > getNextRecords(int numberOfRecords = 999999);

private:
    std::shared_ptr<std::ifstream> filePtr;
};


#endif //TRANSFERWISE_CSVREADER_H
