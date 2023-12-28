#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include <vector>
#include <string>
using namespace std;
struct WindInfo {
    int day;
    int month;
    string direction;
    double speed;
};

bool isWindInDirections(const WindInfo& windInfo);

bool isWindSpeedGreaterThan5(const WindInfo& windInfo);

void shakerSortBySpeed(std::vector<WindInfo>& data);

void mergeSortByDirection(std::vector<WindInfo>& data, int start, int end);

void merge(std::vector<WindInfo>& data, int start, int mid, int end);

#endif  // BOOK_SUBSCRIPTION_H
