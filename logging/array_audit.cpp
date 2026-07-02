// Small program: scan integer arrays and log findings with the logger module.
//
// Compile & run (from logging/):
//   g++ -std=c++17 -Wall -o array_audit array_audit.cpp array_helpers.cpp logger.cpp
//   ./array_audit
//
// Appends to program.log in this folder.

#include "array_helpers.h"
#include "logger.h"

#include <iostream>
#include <string>

using namespace std;

void auditBatch(const string& batchName, const int arr[], int size, int alertThreshold) {
    log("Starting audit for batch: " + batchName, LogLevel::INFO);

    if (size <= 0) {
        log("Batch is empty — skipping metrics", LogLevel::WARNING, batchName);
        return;
    }

    int lowCount = countAtOrBelow(arr, size, alertThreshold);
    int smallest = arrayMin(arr, size);
    int largest = arrayMax(arr, size);
    double avg = arrayAverage(arr, size);

    log("Low readings (<= " + to_string(alertThreshold) + "): " + to_string(lowCount),
        LogLevel::DEBUG,
        batchName);
    log("Average reading: " + to_string(avg), LogLevel::DEBUG, batchName);
    log("Range: " + to_string(smallest) + " to " + to_string(largest), LogLevel::INFO, batchName);

    if (arrayContains(arr, size, 0)) {
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

    if (largest > 90) {
        log("Maximum value " + to_string(largest) + " is unusually high",
            LogLevel::WARNING,
            batchName);
    }

    writeLogEntry("Audit complete", LogLevel::INFO, batchName);
}

void auditDuplicateRisk(const string& batchName, const int arr[], int size) {
    if (size <= 0) return;

    log("Duplicate scan started", LogLevel::DEBUG, batchName);

    for (int i = 0; i < size; i++) {
        int hits = arrayCountValue(arr, size, arr[i]);
        if (hits > 2) {
            log("Value " + to_string(arr[i]) + " appears " + to_string(hits) + " times",
                LogLevel::WARNING,
                batchName);
        }
    }

    writeLogEntry("Duplicate scan complete", LogLevel::INFO, batchName);
}

void auditRangeCompliance(const string& batchName, const int arr[], int size, int low, int high) {
    if (size <= 0) {
        log("Cannot check range on empty batch", LogLevel::ERROR, batchName);
        return;
    }

    int inRange = countInRange(arr, size, low, high);
    int outOfRange = size - inRange;

    log("In-range count [" + to_string(low) + "," + to_string(high) + "]: " + to_string(inRange),
        LogLevel::INFO,
        batchName);
    log("Out-of-range count: " + to_string(outOfRange),
        outOfRange > 0 ? LogLevel::WARNING : LogLevel::INFO,
        batchName);
}

int main() {
    cout << "=== Array audit logger ===" << endl << endl;

    int sensorsA[] = {42, 38, 0, 51, 47};
    int sensorsB[] = {12, 15, 18, 20, 22};
    int sensorsC[] = {88, 88, 88, 91, 92, 88};
    int sensorsD[] = {5, 105, 22, 18, 200};

    auditBatch("sensorsA", sensorsA, 5, 10);
    auditBatch("sensorsB", sensorsB, 5, 10);
    auditBatch("sensorsC-empty", sensorsB, 0, 10);

    auditDuplicateRisk("sensorsC", sensorsC, 6);
    auditRangeCompliance("sensorsD", sensorsD, 5, 0, 100);

    cout << endl << "Summary lines:" << endl;
    cout << summarizeBatch("sensorsA", sensorsA, 5) << endl;
    cout << summarizeBatch("sensorsB", sensorsB, 5) << endl;
    cout << summarizeBatch("sensorsC", sensorsC, 6) << endl;
    cout << summarizeBatch("sensorsD", sensorsD, 5) << endl;

    cout << endl << "Bracketed snapshots:" << endl;
    cout << formatArrayBracketed(sensorsA, 5, "sensorsA") << endl;
    cout << formatArrayBracketed(sensorsC, 6, "sensorsC") << endl;

    cout << endl << "Done. See program.log for full audit trail." << endl;
    return 0;
}
