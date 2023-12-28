#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <vector>
#include "book_subscription.h"
using namespace std;
class FileReader {
public:
    vector<WindInfo> readData(const std::string& filename);

private:
    bool processLine(const std::string& line, WindInfo& wind);
};

#endif  // FILE_READER_H
