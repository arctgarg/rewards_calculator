//
// Created by agarg145 on 2/16/20.
//

#include <fstream>
#include <sstream>
#include "CSVReader.h"

using std::string;
using std::vector;

std::vector<std::vector<std::string> > CSVReader::getNextRecords(int numberOfRecords) {
    std::vector<vector<string> > result;
    std::string line, word;

    int rowCount = 0;
    while(getline(*filePtr, line) && rowCount <= numberOfRecords)
    {
        std::vector<string> transactionRecord;
        std::stringstream s(line);
        while(getline(s, word, ','))
        {
            transactionRecord.push_back(word);
        }
        result.push_back(transactionRecord);
        rowCount++;
    }
    return result;
}

CSVReader::CSVReader(std::string filepath) {
    this->filePtr = std::make_shared<std::ifstream>(filepath);

    std::string headers; // this can be saved as a class member variable, but we dont need this for now.
    getline(*filePtr, headers); //to read the header line
}
