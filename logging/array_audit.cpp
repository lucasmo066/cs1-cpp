// Small program: scan integer arrays and log findings with the logger module.
//
// Compile & run (from logging/):
//   g++ -std=c++17 -Wall -o array_audit array_audit.cpp logger.cpp
//   ./array_audit
//
// Appends to program.log in this folder.

#include "logger.h"

#include <iostream>
#include <string>

using namespace std;

bool containsValue(const int arr[], int size, int target) {
    if (size <= 0) return false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

int countAtOrBelow(const int arr[], int size, int threshold) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= threshold) {
            count++;
        }
    }
    return count;
}

int minValue(const int arr[], int size) {
    if (size < 1) return -1;
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void auditBatch(const string& batchName, const int arr[], int size, int alertThreshold) {
    log("Starting audit for batch: " + batchName, LogLevel::INFO);

    if (size <= 0) {
        log("Batch is empty — skipping metrics", LogLevel::WARNING, batchName);
        return;
    }

    int lowCount = countAtOrBelow(arr, size, alertThreshold);
    int smallest = minValue(arr, size);

    log("Low readings (<= " + to_string(alertThreshold) + "): " + to_string(lowCount),
        LogLevel::DEBUG,
        batchName);

    if (containsValue(arr, size, 0)) {
        log("Zero reading detected in batch", LogLevel::ERROR, batchName);
    }

    if (smallest < alertThreshold) {
        log("Minimum value " + to_string(smallest) + " is below threshold",
            LogLevel::WARNING,
            batchName);
    } else {
        log("Minimum value " + to_string(smallest) + " looks healthy",
            LogLevel::INFO,
            batchName);
    }

    writeLogEntry("Audit complete", LogLevel::INFO, batchName);
}

int main() {
    cout << "=== Array audit logger ===" << endl << endl;

    int sensorsA[] = {42, 38, 0, 51, 47};
    int sensorsB[] = {12, 15, 18, 20, 22};

    auditBatch("sensorsA", sensorsA, 5, 10);
    auditBatch("sensorsB", sensorsB, 5, 10);
    auditBatch("sensorsC", sensorsB, 0, 10);

    cout << endl << "Done. See program.log for full audit trail." << endl;
    return 0;
}
