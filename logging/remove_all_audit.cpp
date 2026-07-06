// Log removeAll — every occurrence removed, size shrinks each shift.
//
// Compile & run (from logging/):
//   g++ -std=c++17 -Wall -o remove_all_audit remove_all_audit.cpp array_helpers.cpp logger.cpp
//   ./remove_all_audit

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

int removeAll(int arr[], int& size, int target) {
    if (size <= 0) {
        return 0;
    }

    int removed = 0;
    int i = 0;
    while (i < size) {
        if (arr[i] == target) {
            log("Removing target at index " + to_string(i),
                LogLevel::DEBUG,
                "target=" + to_string(target));
            shiftLeftFrom(arr, size, i);
            size--;
            removed++;
            logArraySnapshot(arr, size, "after-remove", LogLevel::DEBUG);
        } else {
            i++;
        }
    }
    return removed;
}

void demoRemoveAll() {
    int arr[8] = {5, 5, 10, 5, 5, 20};
    int size = 6;
    int target = 5;

    log("removeAll audit starting", LogLevel::INFO, "target=" + to_string(target));
    logArraySnapshot(arr, size, "before", LogLevel::INFO);

    int count = removeAll(arr, size, target);

    log("Removed " + to_string(count) + " occurrence(s)", LogLevel::INFO);
    logArraySnapshot(arr, size, "after", LogLevel::INFO);
    log(summarizeBatch("final-batch", arr, size), LogLevel::INFO);
}

void demoRemoveAllEmpty() {
    int arr[4] = {1, 2, 3};
    int size = 0;

    int count = removeAll(arr, size, 99);
    log("Empty-array removeAll returned " + to_string(count), LogLevel::WARNING);
}

int main() {
    clearLogFile();
    logSessionBanner("remove_all_audit");

    cout << "=== Remove-all audit logger ===" << endl << endl;

    demoRemoveAll();
    demoRemoveAllEmpty();

    cout << endl << "Done. See program.log for step-by-step removals." << endl;
    return 0;
}
