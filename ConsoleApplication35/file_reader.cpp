#include "file_reader.h" 
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
vector<WindInfo> FileReader::readData(const string& filename) {
    ifstream file(filename);
    string line;
    vector<WindInfo> windData;

    if (file.is_open()) {
        while (getline(file, line)) {
            WindInfo wind;
            if (processLine(line, wind)) {
                windData.push_back(wind);
            }
        }
        file.close();
    }
    else {
        cerr << "Failed to open file: " << filename << endl;
    }

    return windData;
}

bool FileReader::processLine(const string& line, WindInfo& wind) {
    istringstream iss(line);
    int day, month;
    string direction;
    double speed;

    if (iss >> day >> month >> direction >> speed) {
        wind.day = day;
        wind.month = month;
        wind.direction = direction;
        wind.speed = speed;
        return true;
    }
    else {
        cerr << "Invalid line format: " << line << endl;
        return false;
    }
}
