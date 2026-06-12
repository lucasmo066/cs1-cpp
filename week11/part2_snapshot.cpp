// Week 11 — Part 2 snapshot (search + in-place array changes)
// Standalone copy: contains, countValue, fillArray, reverseInPlace
//
// Compile & run:
//   g++ -std=c++17 -Wall -o part2_snapshot part2_snapshot.cpp
//   ./part2_snapshot

#include <iostream>
#include <cassert>
using namespace std;

// ------------------------------------------------------------
// 2a — linear search
// ------------------------------------------------------------
bool contains(int arr[], int size, int target) {
    if (size <= 0) return false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// ------------------------------------------------------------
// 2b — count matches
// ------------------------------------------------------------
int countValue(int arr[], int size, int inputValue) {
    if (size <= 0) return 0;

    int amount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == inputValue) {
            amount++;
        }
    }
    return amount;
}

// ------------------------------------------------------------
// 2c — fill every slot
// ------------------------------------------------------------
void fillArray(int arr[], int size, int fill) {
    if (size <= 0) return;

    for (int i = 0; i < size; i++) {
        arr[i] = fill;
    }
}

// ------------------------------------------------------------
// 2d — reverse in place (swap from both ends)
// ------------------------------------------------------------
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

// ------------------------------------------------------------
// Small demo helper (not in the worksheet — for snapshot output)
// ------------------------------------------------------------
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}

void runSnapshotTests() {
    int a[] = {3, -1, 4, -1, 5};
    int e[] = {1, 2, 2, 2, 3};

    // contains
    assert(contains(a, 5, 4) == true);
    assert(contains(a, 5, 99) == false);
    assert(contains(a, 5, 5) == true);
    assert(contains(a, 0, 3) == false);

    // countValue
    assert(countValue(e, 5, 2) == 3);
    assert(countValue(e, 5, 9) == 0);
    assert(countValue(e, 0, 2) == 0);

    // fillArray
    int fillTest[] = {1, 2, 3};
    fillArray(fillTest, 3, 0);
    assert(fillTest[0] == 0 && fillTest[1] == 0 && fillTest[2] == 0);

    // reverseInPlace
    int revTest[] = {1, 2, 3, 4};
    reverseInPlace(revTest, 4);
    assert(revTest[0] == 4 && revTest[1] == 3 && revTest[2] == 2 && revTest[3] == 1);

    int single[] = {42};
    reverseInPlace(single, 1);
    assert(single[0] == 42);
}

void runSnapshotDemo() {
    int scores[] = {88, 92, 88, 75, 92};
    int size = 5;

    cout << "Scores: ";
    printArray(scores, size);

    cout << "Contains 75? " << (contains(scores, size, 75) ? "yes" : "no") << endl;
    cout << "Contains 100? " << (contains(scores, size, 100) ? "yes" : "no") << endl;
    cout << "Count of 92: " << countValue(scores, size, 92) << endl;

    reverseInPlace(scores, size);
    cout << "After reverse: ";
    printArray(scores, size);

    fillArray(scores, size, -1);
    cout << "After fill(-1): ";
    printArray(scores, size);
}

int main() {
    runSnapshotTests();
    cout << "Part 2 snapshot: all tests passed." << endl << endl;

    cout << "--- Demo ---" << endl;
    runSnapshotDemo();
    return 0;
}
