#include <iostream>
#include <cassert>
using namespace std;

// ============================================================
// ARRAY + FUNCTIONS PRACTICE — Week 11
// Bridges loop_practice (arrays, accumulation) and function_practice.
//
// Write each function yourself below the prompt — signature and body.
// No stubs provided; type everything from scratch.
//
// Compile & run:
//   g++ -std=c++17 -Wall -o array_functions_practice array_functions_practice.cpp
//   ./array_functions_practice
//
// Workflow:
//   1. Read one prompt, write the function under it.
//   2. Test in main() or in runTests() (you write runTests when ready).
//   3. Uncomment matching asserts from Part 5 as you go.
//
// You already did similar array loops in week10/loop_practice.cpp
// (countNegatives, findFirst). Reuse: for (int i = 0; i < size; i++)
//
// DEFENSIVE PROGRAMMING (weave into every function below):
//   Don't trust the caller — check parameters at the TOP, before the loop.
//   Invalid examples: size < 0, size == 0 when you need at least one element.
//
//   Pick ONE policy for this file and stay consistent (write it here):
//     e.g. "if size <= 0, return 0" / "if size <= 0, return -1" /
//          "if size <= 0, print an error and return 0"
//
//   Three approaches from class (use 1 and 2 in practice; avoid exit() here):
//     • Return early with a sentinel or error code
//     • Print an error, then return
//     • Use a safe default only when the spec says so
//
//   After you add a guard, test it in runTests() (Part 5) — silent wrong answers
//   are worse than a crash.
// ============================================================

// ------------------------------------------------------------
// PART 1 — Core array utilities
// Each function takes int arr[] and int size.
// size is how many elements to use (not the full allocated length).
// ------------------------------------------------------------

// 1a. Write a function called sumArray that takes int arr[] and int size,
//     and returns the sum of all elements.
//     Example: {3, -1, 4} with size 3 → 6
//     Hint: same accumulation pattern as sumRange / sumUpTo.
//     Defensive: if size <= 0, return 0 (no loop) — matches sum of nothing.
            int sumArray () {


                return 0;
            }

// 1b. Write a function called averageArray that returns the arithmetic mean
//     as a double.
//     Example: {10, 20, 30} → 20.0
//     Hint: cast to double before dividing so you don't truncate.
//     Defensive: if size <= 0, return 0.0 (cannot divide by zero elements).

double averageArray(int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }

    // TODO: sum the array (loop or call sumArray), cast to double, divide by size
    return 0.0;
}

// 1c. Write a function called maxValue that returns the largest element.
//     Example: {3, 9, 1} → 9
//     Defensive: if size < 1, return -1 (sentinel for "no valid data").

int maxValue(int arr[], int size) {
    if (size < 1) {
        return -1;
    }

    // TODO: loop, track largest seen, return it
    return 0;
}

// 1d. Write a function called minValue that returns the smallest element.
//     Defensive: same invalid-size policy as maxValue.

int minValue(int arr[], int size) {
    if (size < 1) {
        return -1;
    }

    // TODO: loop, track smallest seen, return it
    return 0;
}

// 1e. Write a function called maxIndex that returns the INDEX of the
//     largest element. If the max appears more than once, return the first.
//     Example: {3, 9, 1, 9} → 1  (not 3)
//     Defensive: if size < 1, return -1.


// ------------------------------------------------------------
// PART 2 — Search and in-place changes
// ------------------------------------------------------------

// 2a. Write a function called contains that returns true if target appears
//     anywhere in the array.
//     Defensive: if size <= 0, return false.


// 2b. Write a function called countValue that returns how many times value
//     appears.
//     Example: {1, 2, 2, 2, 3}, value 2 → 3
//     Defensive: if size <= 0, return 0.


// 2c. Write a void function called fillArray that sets every element to value.
//     After fillArray(arr, 5, 0), all five slots should be 0.
//     Defensive: if size <= 0, return immediately (nothing to fill).


// 2d. Write a void function called reverseInPlace that reverses the order
//     of elements in arr.
//     Example: {1, 2, 3, 4} → {4, 3, 2, 1}
//     Hint: swap from both ends moving inward (temp variable is fine).
//     Defensive: if size <= 1, return (already reversed or empty).


// ------------------------------------------------------------
// PART 3 — Functions calling functions
// Don't duplicate logic — call your Part 1 helpers.
// ------------------------------------------------------------

// 3a. Write a void function called printArray that prints elements on one
//     line, space-separated, then endl.
//     Example: {10, 20, 30} prints: 10 20 30


// 3b. Write a void function called printStats that prints:
//       Sum: ...
//       Min: ...
//       Max: ...
//       Average: ...
//     Call sumArray, minValue, maxValue, averageArray — don't re-loop each
//     statistic unless you have a good reason.
//     Defensive: if size <= 0, print an error message and return (don't call
//     helpers with bad size — your helpers should already guard, but main-style
//     functions often check once up front).


// 3c. Write a void function called scaleToMax100 that modifies arr in place
//     so the largest value becomes 100; every other value scales by the same ratio.
//     Example: {50, 100, 25} unchanged (max already 100)
//     Example: {2, 4, 6} → about {33, 67, 100} with integer math
//     Steps:
//       1. Find max (use maxValue or maxIndex).
//       2. If max is 0, do nothing (avoid divide-by-zero) — defensive guard.
//       3. For each i: arr[i] = (arr[i] * 100) / max;
//     Defensive: if size <= 0, return immediately.


// ------------------------------------------------------------
// PART 4 — Copy and compare
// ------------------------------------------------------------

// 4a. Write a void function called copyArray that copies size elements
//     from src into dest. Assume dest has room for at least size elements.
//     Defensive: if size <= 0, return.


// 4b. Write a function called arraysEqual that returns true if both arrays
//     have the same elements in the same order (for the given size).
//     Defensive: if size <= 0, return true (two empty sequences match).


// 4c. Write a function called countAboveAverage that returns how many
//     elements are strictly greater than the average.
//     Example: {10, 20, 30} → average 20 → only 30 counts → return 1
//     Call averageArray once, then loop.
//     Defensive: if size <= 0, return 0.


// ------------------------------------------------------------
// PART 5 — Testing with assert
// Write void runTests() yourself. Declare test arrays inside it, then
// uncomment asserts one function at a time as you finish each part.
//
// Test fixtures you can use:
//   int a[] = {3, -1, 4, -1, 5};
//   int b[] = {10, 20, 30};
//   int e[] = {1, 2, 2, 2, 3};
//
// Part 1:
//   assert(sumArray(a, 5) == 10);
//   assert(sumArray(b, 3) == 60);
//   assert(averageArray(b, 3) == 20.0);
//   assert(maxValue(a, 5) == 5);
//   assert(minValue(a, 5) == -1);
//   assert(maxIndex(a, 5) == 4);
//
// Part 2:
//   assert(contains(a, 5, 4) == true);
//   assert(contains(a, 5, 99) == false);
//   assert(countValue(e, 5, 2) == 3);
//   (write fillArray / reverseInPlace tests yourself too)
//
// Part 3:
//   int scale[] = {2, 4, 6};
//   scaleToMax100(scale, 3);
//   assert(scale[2] == 100);
//
// Part 4:
//   int dest[3];
//   copyArray(dest, b, 3);
//   assert(arraysEqual(dest, b, 3));
//   assert(countAboveAverage(b, 3) == 1);
//
// Defensive (after you add guards — adjust expected values to YOUR policy):
//   assert(sumArray(b, 0) == 0);
//   assert(averageArray(b, 0) == 0.0);
//   assert(maxValue(b, 0) == -1);
//   assert(contains(b, 0, 10) == false);
// ------------------------------------------------------------


// ------------------------------------------------------------
// main() — call runTests() and/or try your own arrays
// ------------------------------------------------------------

int main() {

    return 0;
}
