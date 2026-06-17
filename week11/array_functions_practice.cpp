#include <iostream>
#include <cassert>
using namespace std;

// ============================================================
// ARRAY + FUNCTIONS PRACTICE — Week 11
//
// Write each function yourself below the prompt.
// No stubs provided — type everything from scratch.
//
// Workflow:
//   1. Read one prompt, write the function under it.
//   2. Uncomment matching asserts in runTests() as you go.
//   3. Compile and run after each function.
//
// DEFENSIVE PROGRAMMING (weave into every function):
//   Don't trust the caller — check parameters at the TOP, before the loop.
//   Invalid examples: size < 0, size == 0 when you need at least one element.
//
//   Policy for this file (stay consistent):
//     size <= 0 → return 0 (or 0.0, false, -1 where noted)
//
// Compile & run:
//   g++ -std=c++17 -Wall -o array_functions_practice array_functions_practice.cpp
//   ./array_functions_practice
// ============================================================


// ------------------------------------------------------------
// PART 1 — Core array utilities
// Each function takes int arr[] and int size.
// ------------------------------------------------------------
// 1a. sumArray — return sum of all elements.
//     Example: {3, -1, 4} with size 3 → 6
//     Defensive: size <= 0 → return 0

int sumArray (int arr[], int size) {
    if (size <= 0) return 0;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

// 1b. averageArray — return arithmetic mean as double.
//     Example: {10, 20, 30} → 20.0
//     Hint: cast to double before dividing.
//     Defensive: size <= 0 → return 0.0

  double averageArray (int arr[], int size) {
    if (size <= 0) return 0.0;

    double total = sumArray(arr, size);
    return total / size;
  }

// 1c. maxValue — return the largest element.
//     Example: {3, 9, 1} → 9
//     Defensive: size < 1 → return -1 (sentinel)
int maxValue (int arr[], int size) {
    if (size < 1) return -1; 
    //assumes the first value input is the highest
    int max = arr[0];

    for (int i = 1; i < size; i++ ) {
        //if the i is new high update max
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}


// 1d. minValue — return the smallest element.
//     Defensive: size < 1 → return -1
int minValue (int arr[], int size) {
    //if theres nothing in the array, return error
    if (size < 1) return -1; 
    //begin minimum with first value in the array
    int minimum = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}


// 1e. maxIndex — return the INDEX of the largest element.
//     If max appears more than once, return the first.
//     Example: {3, 9, 1, 9} → 1
//     Defensive: size < 1 → return -1

int maxIndex(int arr[], int size) { 
    if (size < 1) return -1;
    int indexMax = 0;

    for (int i = 1; i < size; i++) {
        //every iteration we want to find out if i is the largest element in indexMax
        if (arr[i] > arr[indexMax]) {
         indexMax = i;   
        }
    }

    return indexMax;
}

// ------------------------------------------------------------
// PART 2 — Search and in-place changes
// ------------------------------------------------------------

// 2a. contains — return true if target appears anywhere.
//     Defensive: size <= 0 → return false
bool contains (int arr[], int size, int target) {
    if (size <= 0) return false;

    //loop through array and ask if element == target 
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        } 
    }

    return false;
}

// 2b. countValue — return how many times value appears.
//     Example: {1, 2, 2, 2, 3}, value 2 → 3
//     Defensive: size <= 0 → return 0
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

// 2c. fillArray (void) — set every element to value.
//     After fillArray(arr, 5, 0), all five slots should be 0.
//     Defensive: size <= 0 → return immediately
void fillArray (int arr[], int size, int fill) {
    if (size <= 0) return;
 
    for(int i = 0; i < size; i++) {
        arr[i] = fill;
    }
}

// 2d. reverseInPlace (void) — reverse order of elements.
//     Example: {1, 2, 3, 4} → {4, 3, 2, 1}
//     Hint: swap from both ends moving inward (temp variable).
//     Defensive: size <= 1 → return
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
// PART 3 — Functions calling functions
// Don't duplicate logic — call your Part 1 helpers.
// ------------------------------------------------------------

// 3a. printArray (void) — print elements space-separated, then endl.
//     Example: {10, 20, 30} prints: 10 20 30
void printArray(int arr[], int size) {
    if (size <= 0) return;

    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}


// 3b. printStats (void) — print Sum, Min, Max, Average.
//     Call sumArray, minValue, maxValue, averageArray.
//     Defensive: size <= 0 → print error and return.
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


// 3c. scaleToMax100 (void) — scale arr in place so largest becomes 100.
//     Example: {2, 4, 6} → {33, 67, 100} (integer math)
//     Steps: find max → if max == 0 do nothing → arr[i] = (arr[i] * 100) / max
//     Defensive: size <= 0 → return
void scaleToMax100(int arr[], int size) {
    if (size <= 0) return;

    int max = maxValue(arr, size);
    if (max == 0) return;

    for (int i = 0; i < size; i++) {
        arr[i] = (arr[i] * 100) / max;
    }
}


// ------------------------------------------------------------
// PART 4 — Copy and compare
// ------------------------------------------------------------

// 4a. copyArray (void) — copy size elements from src into dest.
//     Defensive: size <= 0 → return
void copyArray(int dest[], int src[], int size) {
    if (size <= 0) return;

    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}


// 4b. arraysEqual — return true if same elements in same order.
//     Defensive: size <= 0 → return true
bool arraysEqual(int arr1[], int arr2[], int size) {
    if (size <= 0) return true;

    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}


// 4c. countAboveAverage — return how many elements are strictly
//     greater than the average. Call averageArray once, then loop.
//     Example: {10, 20, 30} → avg 20 → only 30 → return 1
//     Defensive: size <= 0 → return 0
int countAboveAverage(int arr[], int size) {
    if (size <= 0) return 0;

    double avg = averageArray(arr, size);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > avg) {
            count++;
        }
    }
    return count;
}


// ------------------------------------------------------------
// PART 5 — Testing
// Uncomment one block at a time as you finish each part.
// ------------------------------------------------------------

void runTests() {
    int a[] = {3, -1, 4, -1, 5};    // 5 with negatives
    int b[] = {10, 20, 30};        // 3
    int e[] = {1, 2, 2, 2, 3};    // 5

    // Part 1
     assert(sumArray(a, 5) == 10);
     assert(sumArray(b, 3) == 60);
     assert(averageArray(b, 3) == 20.0);
     assert(maxValue(a, 5) == 5);
     assert(minValue(a, 5) == -1);
     assert(maxIndex(a, 5) == 4);

    // Part 2
     assert(contains(a, 5, 4) == true);
     assert(contains(a, 5, 99) == false);
     assert(countValue(e, 5, 2) == 3);
     int fillTest[] = {1, 2, 3};
     fillArray(fillTest, 3, 0);
     assert(fillTest[0] == 0 && fillTest[1] == 0 && fillTest[2] == 0);
     int revTest[] = {1, 2, 3, 4};
     reverseInPlace(revTest, 4);
     assert(revTest[0] == 4 && revTest[1] == 3 && revTest[2] == 2 && revTest[3] == 1);

    // Part 3
     int scale[] = {2, 4, 6};
     scaleToMax100(scale, 3);
     assert(scale[0] == 33 && scale[1] == 66 && scale[2] == 100);

    // Part 4
     int dest[3];
     copyArray(dest, b, 3);
     assert(arraysEqual(dest, b, 3) == true);
     assert(countAboveAverage(b, 3) == 1);

    // Defensive
     assert(sumArray(b, 0) == 0);
     assert(averageArray(b, 0) == 0.0);
     assert(maxValue(b, 0) == -1);
     assert(contains(b, 0, 10) == false);
     assert(countValue(b, 0, 10) == 0);
     assert(arraysEqual(b, b, 0) == true);
     assert(countAboveAverage(b, 0) == 0);
}

// ------------------------------------------------------------
// EXTENDED PRACTICE — extra demos and edge-case tests
// ------------------------------------------------------------

void runExtendedTests() {
    int negatives[] = {-5, -2, -10, -2};
    assert(maxValue(negatives, 4) == -2);
    assert(minValue(negatives, 4) == -10);
    assert(maxIndex(negatives, 4) == 1);
    assert(sumArray(negatives, 4) == -19);

    int dupes[] = {3, 9, 1, 9};
    assert(maxIndex(dupes, 4) == 1);
    assert(contains(dupes, 4, 9) == true);
    assert(countValue(dupes, 4, 9) == 2);

    int single[] = {42};
    assert(sumArray(single, 1) == 42);
    assert(averageArray(single, 1) == 42.0);
    assert(maxValue(single, 1) == 42);
    assert(minValue(single, 1) == 42);
    assert(maxIndex(single, 1) == 0);

    int zeros[] = {0, 0, 0};
    scaleToMax100(zeros, 3);
    assert(zeros[0] == 0 && zeros[1] == 0 && zeros[2] == 0);

    int copySrc[] = {7, 8, 9};
    int copyDest[3] = {0, 0, 0};
    copyArray(copyDest, copySrc, 3);
    assert(arraysEqual(copyDest, copySrc, 3) == true);

    int notEqualA[] = {1, 2, 3};
    int notEqualB[] = {1, 2, 4};
    assert(arraysEqual(notEqualA, notEqualB, 3) == false);

    int aboveAvg[] = {10, 20, 30, 40};
    assert(countAboveAverage(aboveAvg, 4) == 2);

    int palindrome[] = {1, 2, 3, 2, 1};
    reverseInPlace(palindrome, 5);
    assert(palindrome[0] == 1 && palindrome[2] == 3 && palindrome[4] == 1);

    int fillLarge[] = {5, 5, 5, 5, 5};
    fillArray(fillLarge, 5, 99);
    assert(fillLarge[0] == 99 && fillLarge[4] == 99);
}

void runWorksheetDemo() {
    cout << endl << "=== Array Functions Demo ===" << endl;

    int sample[] = {12, 45, 7, 45, 19};
    int sampleSize = 5;

    cout << "Sample array: ";
    printArray(sample, sampleSize);

    cout << endl << "Stats:" << endl;
    printStats(sample, sampleSize);

    cout << endl << "Search results:" << endl;
    cout << "Contains 45? " << (contains(sample, sampleSize, 45) ? "yes" : "no") << endl;
    cout << "Contains 100? " << (contains(sample, sampleSize, 100) ? "yes" : "no") << endl;
    cout << "Count of 45: " << countValue(sample, sampleSize, 45) << endl;
    cout << "Count above average: " << countAboveAverage(sample, sampleSize) << endl;
    cout << "Max index: " << maxIndex(sample, sampleSize) << endl;

    int scaled[] = {2, 4, 6, 8};
    cout << endl << "Before scale: ";
    printArray(scaled, 4);
    scaleToMax100(scaled, 4);
    cout << "After scaleToMax100: ";
    printArray(scaled, 4);

    int reversed[] = {10, 20, 30};
    cout << endl << "Before reverse: ";
    printArray(reversed, 3);
    reverseInPlace(reversed, 3);
    cout << "After reverseInPlace: ";
    printArray(reversed, 3);

    int backup[3];
    copyArray(backup, reversed, 3);
    cout << endl << "Copied array: ";
    printArray(backup, 3);
    cout << "Arrays equal after copy? "
         << (arraysEqual(backup, reversed, 3) ? "yes" : "no") << endl;

    cout << endl << "Defensive checks:" << endl;
    printStats(sample, 0);
    cout << "minValue(empty): " << minValue(sample, 0) << endl;
    cout << "contains(empty, 12): " << (contains(sample, 0, 12) ? "yes" : "no") << endl;
}

void runPracticeScenarios() {
    // Scenario 1: grade curve style scaling
    int grades[] = {72, 85, 91, 68, 95};
    int gradeCount = 5;
    cout << endl << "--- Scenario: grade scaling ---" << endl;
    printArray(grades, gradeCount);
    scaleToMax100(grades, gradeCount);
    printArray(grades, gradeCount);

    // Scenario 2: duplicate detection
    int votes[] = {1, 2, 1, 3, 1, 2, 1};
    int voteCount = 7;
    cout << endl << "--- Scenario: vote counting ---" << endl;
    cout << "Votes for candidate 1: " << countValue(votes, voteCount, 1) << endl;
    cout << "Votes for candidate 2: " << countValue(votes, voteCount, 2) << endl;
    cout << "Votes for candidate 3: " << countValue(votes, voteCount, 3) << endl;

    // Scenario 3: snapshot and restore with copyArray
    int original[] = {4, 8, 15, 16, 23, 42};
    int snapshot[6];
    copyArray(snapshot, original, 6);
    reverseInPlace(original, 6);
    cout << endl << "--- Scenario: snapshot restore ---" << endl;
    cout << "Reversed (mutated): ";
    printArray(original, 6);
    copyArray(original, snapshot, 6);
    cout << "Restored from snapshot: ";
    printArray(original, 6);
    assert(arraysEqual(original, snapshot, 6) == true);
}

// ------------------------------------------------------------
// BONUS UTILITIES — extra array drills beyond the worksheet
// ------------------------------------------------------------

int countBelowValue(int arr[], int size, int threshold) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < threshold) {
            count++;
        }
    }
    return count;
}

int countInRange(int arr[], int size, int low, int high) {
    if (size <= 0) return 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= low && arr[i] <= high) {
            count++;
        }
    }
    return count;
}

void clampArray(int arr[], int size, int low, int high) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        if (arr[i] < low) {
            arr[i] = low;
        } else if (arr[i] > high) {
            arr[i] = high;
        }
    }
}

bool isSortedAscending(int arr[], int size) {
    if (size <= 1) return true;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void shiftLeft(int arr[], int size) {
    if (size <= 1) return;
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;
}

void runBonusTests() {
    int below[] = {3, 9, 1, 15, 2};
    assert(countBelowValue(below, 5, 5) == 3);
    assert(countInRange(below, 5, 3, 10) == 2);

    int clamped[] = {-5, 10, 50, 200};
    clampArray(clamped, 4, 0, 100);
    assert(clamped[0] == 0 && clamped[1] == 10 && clamped[3] == 100);

    int sorted[] = {1, 2, 3, 4, 5};
    int messy[] = {1, 3, 2, 4};
    assert(isSortedAscending(sorted, 5) == true);
    assert(isSortedAscending(messy, 4) == false);

    int shift[] = {10, 20, 30, 40};
    shiftLeft(shift, 4);
    assert(shift[0] == 20 && shift[1] == 30 && shift[2] == 40 && shift[3] == 0);
}

void runBonusDemo() {
    cout << endl << "=== Bonus utilities demo ===" << endl;

    int temps[] = {-3, 14, 22, 37, 41, 18, 5};
    cout << "Temperatures: ";
    printArray(temps, 7);
    cout << "Readings in comfort zone (10-30): "
         << countInRange(temps, 7, 10, 30) << endl;
    cout << "Readings below 10: " << countBelowValue(temps, 7, 10) << endl;

    clampArray(temps, 7, 0, 35);
    cout << "After clamp (0-35): ";
    printArray(temps, 7);

    int queue[] = {100, 200, 300, 400, 500};
    cout << endl << "Queue before shift: ";
    printArray(queue, 5);
    shiftLeft(queue, 5);
    cout << "Queue after shiftLeft: ";
    printArray(queue, 5);

    int ordered[] = {2, 4, 6, 8};
    cout << "Is ordered ascending? "
         << (isSortedAscending(ordered, 4) ? "yes" : "no") << endl;
}

int main() {
    runTests();
    runExtendedTests();
    runBonusTests();
    cout << "All tests passed." << endl;

    runWorksheetDemo();
    runPracticeScenarios();
    runBonusDemo();

    cout << endl << "Worksheet complete — Parts 1 through 4 finished." << endl;
    return 0;
}