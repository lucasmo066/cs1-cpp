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


// 1e. maxIndex — return the INDEX of the largest element.
//     If max appears more than once, return the first.
//     Example: {3, 9, 1, 9} → 1
//     Defensive: size < 1 → return -1


// ------------------------------------------------------------
// PART 2 — Search and in-place changes
// ------------------------------------------------------------

// 2a. contains — return true if target appears anywhere.
//     Defensive: size <= 0 → return false


// 2b. countValue — return how many times value appears.
//     Example: {1, 2, 2, 2, 3}, value 2 → 3
//     Defensive: size <= 0 → return 0


// 2c. fillArray (void) — set every element to value.
//     After fillArray(arr, 5, 0), all five slots should be 0.
//     Defensive: size <= 0 → return immediately


// 2d. reverseInPlace (void) — reverse order of elements.
//     Example: {1, 2, 3, 4} → {4, 3, 2, 1}
//     Hint: swap from both ends moving inward (temp variable).
//     Defensive: size <= 1 → return


// ------------------------------------------------------------
// PART 3 — Functions calling functions
// Don't duplicate logic — call your Part 1 helpers.
// ------------------------------------------------------------

// 3a. printArray (void) — print elements space-separated, then endl.
//     Example: {10, 20, 30} prints: 10 20 30


// 3b. printStats (void) — print Sum, Min, Max, Average.
//     Call sumArray, minValue, maxValue, averageArray.
//     Defensive: size <= 0 → print error and return.


// 3c. scaleToMax100 (void) — scale arr in place so largest becomes 100.
//     Example: {2, 4, 6} → {33, 67, 100} (integer math)
//     Steps: find max → if max == 0 do nothing → arr[i] = (arr[i] * 100) / max
//     Defensive: size <= 0 → return


// ------------------------------------------------------------
// PART 4 — Copy and compare
// ------------------------------------------------------------

// 4a. copyArray (void) — copy size elements from src into dest.
//     Defensive: size <= 0 → return


// 4b. arraysEqual — return true if same elements in same order.
//     Defensive: size <= 0 → return true


// 4c. countAboveAverage — return how many elements are strictly
//     greater than the average. Call averageArray once, then loop.
//     Example: {10, 20, 30} → avg 20 → only 30 → return 1
//     Defensive: size <= 0 → return 0


// ------------------------------------------------------------
// PART 5 — Testing
// Uncomment one block at a time as you finish each part.
// ------------------------------------------------------------

void runTests() {
    int a[] = {3, -1, 4, -1, 5};
    int b[] = {10, 20, 30};
  //  int e[] = {1, 2, 2, 2, 3};

    // Part 1
     assert(sumArray(a, 5) == 10);
     assert(sumArray(b, 3) == 60);
     assert(averageArray(b, 3) == 20.0);
     assert(maxValue(a, 5) == 5);
   //  assert(minValue(a, 5) == -1);
  //   assert(maxIndex(a, 5) == 4);

    // Part 2
    // assert(contains(a, 5, 4) == true);
    // assert(contains(a, 5, 99) == false);
    // assert(countValue(e, 5, 2) == 3);
    // int fillTest[] = {1, 2, 3};
    // fillArray(fillTest, 3, 0);
    // assert(fillTest[0] == 0 && fillTest[1] == 0 && fillTest[2] == 0);
    // int revTest[] = {1, 2, 3, 4};
    // reverseInPlace(revTest, 4);
    // assert(revTest[0] == 4 && revTest[1] == 3 && revTest[2] == 2 && revTest[3] == 1);

    // Part 3
    // int scale[] = {2, 4, 6};
    // scaleToMax100(scale, 3);
    // assert(scale[2] == 100);

    // Part 4
    // int dest[3];
    // copyArray(dest, b, 3);
    // assert(arraysEqual(dest, b, 3) == true);
    // assert(countAboveAverage(b, 3) == 1);

    // Defensive
     assert(sumArray(b, 0) == 0);
     assert(averageArray(b, 0) == 0.0);
    // assert(maxValue(b, 0) == -1);
    // assert(contains(b, 0, 10) == false);
}

int main() {
    runTests();
    cout << "All tests passed." << endl;
    return 0;
}