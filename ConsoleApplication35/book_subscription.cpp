#include "book_subscription.h"
#include <algorithm>
using namespace std;

bool isWindInDirections(const WindInfo& windInfo) {
    string direction = windInfo.direction;
    return (direction == "West" || direction == "NorthWest" || direction == "North");
}

bool isWindSpeedGreaterThan5(const WindInfo& windInfo) {
    return (windInfo.speed > 5.0);
}

void shakerSortBySpeed(vector<WindInfo>& data) {
    int left = 0;
    int right = data.size() - 1;
    bool swapped = false;

    do {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; ++i) {
            if (data[i].speed < data[i + 1].speed) {
                swap(data[i], data[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --right;

        // Проход справа налево
        for (int i = right; i > left; --i) {
            if (data[i - 1].speed < data[i].speed) {
                swap(data[i - 1], data[i]);
                swapped = true;
            }
        }

        ++left;
    } while (swapped);
}

void merge(vector<WindInfo>& data, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<WindInfo> leftData(n1);
    vector<WindInfo> rightData(n2);

    for (int i = 0; i < n1; ++i) {
        leftData[i] = data[start + i];
    }

    for (int j = 0; j < n2; ++j) {
        rightData[j] = data[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (leftData[i].direction < rightData[j].direction ||
            (leftData[i].direction == rightData[j].direction && leftData[i].month < rightData[j].month) ||
            (leftData[i].direction == rightData[j].direction && leftData[i].month == rightData[j].month &&
                leftData[i].day < rightData[j].day)) {
            data[k] = leftData[i];
            ++i;
        }
        else {
            data[k] = rightData[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        data[k] = leftData[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        data[k] = rightData[j];
        ++j;
        ++k;
    }
}

void mergeSortByDirection(vector<WindInfo>& data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSortByDirection(data, start, mid);
        mergeSortByDirection(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}