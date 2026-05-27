#include <iostream>
#include <cassert>
using namespace std;

// ============================================================
// PASS BY REFERENCE — Week 11 (short focused drill)
// Do AFTER array_functions_practice.
//
// Write each function yourself under the prompt — signature and body.
//
// Key ideas:
//   - Pass-by-value copies — changes inside the function don't affect caller.
//   - Pass-by-reference (int& x) — changes stick in the caller's variable.
//   - int arr[] already passes array data by reference; use int& for a single
//     int the caller owns (size, minOut, maxOut, etc.).
//
// Compile:
//   g++ -std=c++17 -Wall -o pass_by_reference pass_by_reference.cpp
// ============================================================

// 1. Write void swap(int& a, int& b) — exchange two ints in the caller's scope.
//    Hint: classic three-way swap with a temp variable.


// 2. Write void doubleValue(int& n) — multiply the caller's variable by 2.
//    Example: int x = 5; doubleValue(x);  // x is now 10


// 3. Write void findMinMax(int arr[], int size, int& minOut, int& maxOut)
//    Assume size >= 1. Set minOut and maxOut to the min/max in the array.
//    Example:
//      int lo, hi;
//      findMinMax(data, 5, lo, hi);


// 4. Write bool removeFirst(int arr[], int& size, int target)
//    If target is found: shift elements left, decrement size, return true.
//    If not found: return false, size unchanged.
//    Example: {10,20,30}, size=3, target=20 → {10,30,?}, size=2


// 5. Write void sortTwo(int& a, int& b) — leave a <= b (swap if needed).


// 6. (Think about, no code required) — findMinMax gets two outputs in one pass.
//    Compare to separate minValue/maxValue from array_functions_practice.cpp.
//    When would you return one value vs use out-parameters?


// ------------------------------------------------------------
// Testing — write void runTests() and uncomment asserts as you go:
//
//   int x = 3, y = 7;
//   swap(x, y);
//   assert(x == 7 && y == 3);
//
//   int n = 5;
//   doubleValue(n);
//   assert(n == 10);
//
//   int data[] = {4, -2, 9, 9, 1};
//   int lo = 0, hi = 0;
//   findMinMax(data, 5, lo, hi);
//   assert(lo == -2 && hi == 9);
//
//   int a = 10, b = 5;
//   sortTwo(a, b);
//   assert(a == 5 && b == 10);
//
//   int arr[] = {1, 2, 3};
//   int sz = 3;
//   assert(removeFirst(arr, sz, 2) == true);
//   assert(sz == 2 && arr[0] == 1 && arr[1] == 3);
// ------------------------------------------------------------

int main() {

    return 0;
}
