// Week 11 — Part 1 snapshot (sumArray through minValue)
// Standalone copy of completed array utilities for repo history.
//
// Compile & run:
//   g++ -std=c++17 -Wall -o part1_snapshot part1_snapshot.cpp
//   ./part1_snapshot

#include <iostream>
#include <cassert>
using namespace std;

int sumArray(int arr[], int size) {
    if (size <= 0) return 0;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double averageArray(int arr[], int size) {
    if (size <= 0) return 0.0;

    double total = sumArray(arr, size);
    return total / size;
}

int maxValue(int arr[], int size) {
    if (size < 1) return -1;

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minValue(int arr[], int size) {
    if (size < 1) return -1;

    int minimum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

void runSnapshotTests() {
    int a[] = {3, -1, 4, -1, 5};
    int b[] = {10, 20, 30};

    assert(sumArray(a, 5) == 10);
    assert(sumArray(b, 3) == 60);
    assert(sumArray(b, 0) == 0);

    assert(averageArray(b, 3) == 20.0);
    assert(averageArray(b, 0) == 0.0);

    assert(maxValue(a, 5) == 5);
    assert(maxValue(b, 0) == -1);

    assert(minValue(a, 5) == -1);
    assert(minValue(b, 0) == -1);
}

int main() {
    runSnapshotTests();
    cout << "Part 1 snapshot: all tests passed." << endl;
    return 0;
}
