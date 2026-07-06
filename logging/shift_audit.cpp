// Log array shift operations — mirrors Week 11 removeAt / insertAt patterns.
//
// Compile & run (from logging/):
//   g++ -std=c++17 -Wall -o shift_audit shift_audit.cpp array_helpers.cpp logger.cpp
//   ./shift_audit

#include "array_helpers.h"
#include "logger.h"

#include <iostream>
#include <string>

using namespace std;

void shiftLeftFrom(int arr[], int size, int fromIndex) {
    if (fromIndex < 0 || fromIndex >= size) {
        return;
    }
    for (int j = fromIndex; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
}

void shiftRightFrom(int arr[], int size, int fromIndex) {
    if (fromIndex < 0 || fromIndex > size) {
        return;
    }
    for (int j = size - 1; j >= fromIndex; j--) {
        arr[j + 1] = arr[j];
    }
}

bool removeAt(int arr[], int& size, int index) {
    if (size <= 0 || index < 0 || index >= size) {
        return false;
    }
    shiftLeftFrom(arr, size, index);
    size--;
    return true;
}

bool insertAt(int arr[], int& size, int capacity, int index, int value) {
    if (size >= capacity || index < 0 || index > size) {
        return false;
    }
    shiftRightFrom(arr, size, index);
    arr[index] = value;
    size++;
    return true;
}

void logShiftStep(const string& action, const int arr[], int size, LogLevel level) {
    log(action, level, "size=" + to_string(size));
    logArraySnapshot(arr, size, action + "-state", LogLevel::DEBUG);
}

void demoRemoveAt() {
    int arr[8] = {10, 20, 30, 40, 50};
    int size = 5;

    log("Shift audit: removeAt demo starting", LogLevel::INFO);
    logShiftStep("initial", arr, size, LogLevel::INFO);

    if (removeAt(arr, size, 2)) {
        logShiftStep("after removeAt index 2", arr, size, LogLevel::INFO);
    } else {
        log("removeAt failed at index 2", LogLevel::ERROR);
    }
}

void demoInsertAt() {
    int arr[8] = {10, 20, 30};
    int size = 3;

    log("Shift audit: insertAt demo starting", LogLevel::INFO);
    logShiftStep("initial", arr, size, LogLevel::INFO);

    if (insertAt(arr, size, 8, 1, 99)) {
        logShiftStep("after insertAt index 1 value 99", arr, size, LogLevel::INFO);
    } else {
        log("insertAt failed at index 1", LogLevel::ERROR);
    }
}

void demoFailedInsert() {
    int arr[4] = {1, 2, 3, 4};
    int size = 4;

    log("Shift audit: full-array insert guard", LogLevel::WARNING);
    if (!insertAt(arr, size, 4, 2, 99)) {
        log("insertAt correctly rejected — array at capacity", LogLevel::WARNING, "capacity=4");
        logShiftStep("unchanged after rejected insert", arr, size, LogLevel::INFO);
    }
}

int main() {
    clearLogFile();
    logSessionBanner("shift_audit");

    cout << "=== Shift audit logger ===" << endl << endl;

    demoRemoveAt();
    demoInsertAt();
    demoFailedInsert();

    cout << endl << "Done. See program.log for before/after array states." << endl;
    return 0;
}
