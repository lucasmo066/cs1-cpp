#include "array_helpers.h"
#include "logger.h"

#include <sstream>

using namespace std;

int arraySum(const int arr[], int size) {
    if (size <= 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double arrayAverage(const int arr[], int size) {
    if (size <= 0) return 0.0;
    return static_cast<double>(arraySum(arr, size)) / size;
}

int arrayMin(const int arr[], int size) {
    if (size < 1) return -1;
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int arrayMax(const int arr[], int size) {
    if (size < 1) return -1;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

bool arrayContains(const int arr[], int size, int target) {
    if (size <= 0) return false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

int arrayCountValue(const int arr[], int size, int value) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) count++;
    }
    return count;
}

int countAtOrBelow(const int arr[], int size, int threshold) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= threshold) count++;
    }
    return count;
}

int countAboveValue(const int arr[], int size, int threshold) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > threshold) count++;
    }
    return count;
}

int countInRange(const int arr[], int size, int low, int high) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= low && arr[i] <= high) count++;
    }
    return count;
}

void arrayToCsvLine(const int arr[], int size, string& out) {
    ostringstream line;
    for (int i = 0; i < size; i++) {
        line << arr[i];
        if (i < size - 1) line << ',';
    }
    out = line.str();
}

string summarizeBatch(const string& name, const int arr[], int size) {
    if (size <= 0) return name + ": empty batch";

    ostringstream summary;
    summary << name << " | count=" << size
            << " sum=" << arraySum(arr, size)
            << " avg=" << arrayAverage(arr, size)
            << " min=" << arrayMin(arr, size)
            << " max=" << arrayMax(arr, size);
    return summary.str();
}

string formatArrayBracketed(const int arr[], int size, const string& label) {
    ostringstream line;
    line << label << ": [";
    if (size <= 0) {
        line << "]";
        return line.str();
    }
    for (int i = 0; i < size; i++) {
        line << arr[i];
        if (i < size - 1) {
            line << ", ";
        }
    }
    line << "]";
    return line.str();
}

void logArraySnapshot(const int arr[], int size, const string& label, LogLevel level) {
    string snapshot = formatArrayBracketed(arr, size, label);
    string context = "size=" + to_string(size);
    log(snapshot, level, context);
}
