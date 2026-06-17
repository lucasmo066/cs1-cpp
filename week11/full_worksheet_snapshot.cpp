// Week 11 — Full worksheet snapshot (Parts 1–4 complete)
//
// Compile & run:
//   g++ -std=c++17 -Wall -o full_worksheet_snapshot full_worksheet_snapshot.cpp
//   ./full_worksheet_snapshot

#include <iostream>
#include <cassert>
using namespace std;

// --- Part 1 ---
int sumArray(int arr[], int size) {
    if (size <= 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

double averageArray(int arr[], int size) {
    if (size <= 0) return 0.0;
    return static_cast<double>(sumArray(arr, size)) / size;
}

int maxValue(int arr[], int size) {
    if (size < 1) return -1;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int minValue(int arr[], int size) {
    if (size < 1) return -1;
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int maxIndex(int arr[], int size) {
    if (size < 1) return -1;
    int best = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[best]) best = i;
    }
    return best;
}

// --- Part 2 ---
bool contains(int arr[], int size, int target) {
    if (size <= 0) return false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

int countValue(int arr[], int size, int value) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) count++;
    }
    return count;
}

void fillArray(int arr[], int size, int value) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) arr[i] = value;
}

void reverseInPlace(int arr[], int size) {
    if (size <= 1) return;
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// --- Part 3 ---
void printArray(int arr[], int size) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ' ';
    }
    cout << endl;
}

void printStats(int arr[], int size) {
    if (size <= 0) {
        cout << "Error: cannot print stats for empty array." << endl;
        return;
    }
    cout << "Sum: " << sumArray(arr, size) << endl;
    cout << "Min: " << minValue(arr, size) << endl;
    cout << "Max: " << maxValue(arr, size) << endl;
    cout << "Average: " << averageArray(arr, size) << endl;
}

void scaleToMax100(int arr[], int size) {
    if (size <= 0) return;
    int max = maxValue(arr, size);
    if (max == 0) return;
    for (int i = 0; i < size; i++) {
        arr[i] = (arr[i] * 100) / max;
    }
}

// --- Part 4 ---
void copyArray(int dest[], int src[], int size) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) dest[i] = src[i];
}

bool arraysEqual(int arr1[], int arr2[], int size) {
    if (size <= 0) return true;
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int countAboveAverage(int arr[], int size) {
    if (size <= 0) return 0;
    double avg = averageArray(arr, size);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > avg) count++;
    }
    return count;
}

// --- Bonus helpers for snapshot ---
int countBelowValue(int arr[], int size, int threshold) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < threshold) count++;
    }
    return count;
}

void clampArray(int arr[], int size, int low, int high) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        if (arr[i] < low) arr[i] = low;
        else if (arr[i] > high) arr[i] = high;
    }
}

bool isSortedAscending(int arr[], int size) {
    if (size <= 1) return true;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

void runCoreTests() {
    int a[] = {3, -1, 4, -1, 5};
    int b[] = {10, 20, 30};
    int e[] = {1, 2, 2, 2, 3};

    assert(sumArray(a, 5) == 10);
    assert(averageArray(b, 3) == 20.0);
    assert(maxValue(a, 5) == 5);
    assert(minValue(a, 5) == -1);
    assert(maxIndex(a, 5) == 4);

    assert(contains(a, 5, 4));
    assert(!contains(a, 5, 99));
    assert(countValue(e, 5, 2) == 3);

    int fillTest[] = {1, 2, 3};
    fillArray(fillTest, 3, 0);
    assert(fillTest[0] == 0 && fillTest[2] == 0);

    int revTest[] = {1, 2, 3, 4};
    reverseInPlace(revTest, 4);
    assert(revTest[0] == 4 && revTest[3] == 1);

    int scale[] = {2, 4, 6};
    scaleToMax100(scale, 3);
    assert(scale[2] == 100);

    int dest[3];
    copyArray(dest, b, 3);
    assert(arraysEqual(dest, b, 3));
    assert(countAboveAverage(b, 3) == 1);
}

void runBonusTests() {
    int data[] = {5, 50, 150, -3, 8};
    assert(countBelowValue(data, 5, 10) == 2);

    int clampTest[] = {1, 50, 200};
    clampArray(clampTest, 3, 10, 100);
    assert(clampTest[0] == 10 && clampTest[1] == 50 && clampTest[2] == 100);

    int sorted[] = {1, 2, 3, 4};
    int unsorted[] = {1, 3, 2, 4};
    assert(isSortedAscending(sorted, 4));
    assert(!isSortedAscending(unsorted, 4));
}

void runShowcase() {
    cout << endl << "=== Full Worksheet Showcase ===" << endl;

    int inventory[] = {14, 7, 22, 7, 31, 7, 18};
    cout << "Inventory: ";
    printArray(inventory, 7);
    printStats(inventory, 7);
    cout << "Count of 7: " << countValue(inventory, 7, 7) << endl;
    cout << "Above average: " << countAboveAverage(inventory, 7) << endl;

    int curve[] = {55, 70, 82, 91, 64};
    cout << endl << "Before curve: ";
    printArray(curve, 5);
    scaleToMax100(curve, 5);
    cout << "After curve: ";
    printArray(curve, 5);

    int backup[5];
    copyArray(backup, curve, 5);
    reverseInPlace(curve, 5);
    cout << "Reversed curve: ";
    printArray(curve, 5);
    cout << "Backup still equal? "
         << (arraysEqual(backup, curve, 5) ? "yes" : "no") << endl;
}

int main() {
    runCoreTests();
    runBonusTests();
    cout << "Full worksheet snapshot: all tests passed." << endl;
    runShowcase();
    return 0;
}
