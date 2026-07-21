#include <iostream>
#include <cassert>
using namespace std;

// ============================================================
// SHIFT LOOP DRILL — Week 11
// Do AFTER pass_by_reference Part 3 (removeFirst, insertAt).
//
// Why this file exists:
//   Part 3 combines THREE skills at once — find/guard, shift loop,
//   and int& size. This drill pulls them apart, then puts them
//   back together in harder steps.
//
// The two patterns (know these cold):
//
//   SHIFT LEFT (remove / close a gap) — loop FORWARD from the gap:
//     for (int j = fromIndex; j < size - 1; j++) {
//         arr[j] = arr[j + 1];
//     }
//     size--;   // caller or callee, depending on the function
//
//   SHIFT RIGHT (insert / open a gap) — loop BACKWARD from the end:
//     for (int j = size - 1; j >= fromIndex; j--) {
//         arr[j + 1] = arr[j];
//     }
//     arr[fromIndex] = value;
//     size++;
//
// Compile:
//   g++ -std=c++17 -Wall -o shift_loop_drill shift_loop_drill.cpp
// ============================================================


// ------------------------------------------------------------
// PART 1 — Shift loops ONLY (no size change, no search)
// These isolate the inner loop from pass_by_reference Part 3.
// Caller is responsible for size-- / size++ / assigning value.
// ------------------------------------------------------------

// 1a. Write void shiftLeftFrom(int arr[], int size, int fromIndex)
//     Starting at fromIndex, shift every element one slot LEFT.
//     Same loop body as removeFirst's inner loop.
//     Does NOT change size — caller decrements size after calling.
//     Defensive: if fromIndex < 0 or fromIndex >= size, return immediately.
//     Example: arr={10,20,30,40}, size=4, fromIndex=1
//              → arr={10,30,40,40}  (size still 4 until caller fixes it)

void shiftLeftFrom(int arr[], int size, int fromIndex) {
    //defensive
    if (fromIndex < 0 || fromIndex >= size) return;

   for (int i = fromIndex; i < size - 1; i++){
        arr[i] = arr[i + 1];
   }
}

// 1b. Write void shiftRightFrom(int arr[], int size, int fromIndex)
//     Starting at fromIndex, shift every element one slot RIGHT.
//     Same loop body as insertAt's inner loop (before arr[index]=value).
//     Does NOT insert a value or change size.
//     Defensive: if fromIndex < 0 or fromIndex > size, return immediately.
//     Example: arr={10,20,30}, size=3, fromIndex=1
//              → arr={10,20,20,30}  (gap not filled yet; size still 3)
void shiftRightFrom(int arr[], int size, int fromIndex) {
    //defensive
    if (fromIndex < 0 || fromIndex > size) return;

    for (int i = size -1; i >= fromIndex; i--) {
        arr[i + 1] = arr[i];
    }
}

// ------------------------------------------------------------
// PART 2 — Known index (shift + size, no search)
// These give you the index directly so you practice shift + int& size.
// ------------------------------------------------------------

// 2a. Write bool removeAt(int arr[], int& size, int index)
//     Remove the element at index: shift left, size--, return true.
//     Defensive: if size <= 0 or index < 0 or index >= size, return false.
//     Hint: reuse shiftLeftFrom, or write the loop inline.
//     Example: arr={10,20,30}, size=3, index=0 → arr={20,30,?}, size=2
bool removeAt(int arr[], int& size, int index) {
    if (size <= 0 || index < 0 || index >= size) return false;

    shiftLeftFrom(arr, size, index);
    size--;
    return true;
}

// 2b. Write bool appendValue(int arr[], int& size, int capacity, int value)
//     Insert value at the end (index == size).
//     Defensive: if size >= capacity, return false.
//     Example: arr={10,20}, size=2, capacity=5, value=30
//              → arr={10,20,30,?,?}, size=3
//     Note: the shift loop should NOT run when inserting at index == size.
bool appendValue(int arr[], int& size, int capacity, int value) {
    if (size >= capacity) return false;

    arr[size] = value;
    size++;
    return true;
}

// 2c. Write bool prependValue(int arr[], int& size, int capacity, int value)
//     Insert value at index 0 (front of the array).
//     Defensive: if size >= capacity, return false.
//     Example: arr={20,30}, size=2, capacity=5, value=10
//              → arr={10,20,30,?,?}, size=3


// ------------------------------------------------------------
// PART 3 — Full replay (find + shift + size)
// Same specs as pass_by_reference #8 and #9.
// Try writing these WITHOUT peeking at pass_by_reference.cpp first.
// ------------------------------------------------------------

// 3a. Write bool removeFirst(int arr[], int& size, int target)
//     Find the FIRST occurrence of target, shift left, size--, return true.
//     Not found → return false, size unchanged.
//     Defensive: size <= 0 → return false.
//     Example: arr={5,5,5}, size=3, target=5 → arr={5,5,?}, size=2
//              (only the FIRST 5 is removed)


// 3b. Write bool insertAt(int arr[], int& size, int capacity,
//                         int index, int value)
//     Shift right at index, insert value, size++, return true.
//     Defensive: size >= capacity OR index < 0 OR index > size → false.
//     Example: arr={10,20,30}, size=3, capacity=5, index=1, value=99
//              → arr={10,99,20,30,?}, size=4



// ------------------------------------------------------------
// PART 4 — Harder: multiple operations
// ------------------------------------------------------------

// 4a. Write int removeAll(int arr[], int& size, int target)
//     Remove EVERY occurrence of target (not just the first).
//     Return how many elements were removed.
//     Defensive: if size <= 0, return 0.
//     Hint: when you remove at index i and shift left, the NEXT
//     element slides INTO index i — so do NOT always i++.
//     Example: arr={5,5,10,5}, size=4, target=5 → arr={10,?}, size=1, return 3


// 4b. Write bool insertSorted(int arr[], int& size, int capacity, int value)
//     Insert value so the array stays in non-decreasing order.
//     Find the correct index first (first position where value fits),
//     then shift right and insert.
//     Defensive: size >= capacity → return false.
//     Example: arr={10,20,40}, size=3, capacity=6, value=25
//              → arr={10,20,25,40,?,?}, size=4
//     Example: arr={10,20,30}, size=3, capacity=6, value=5
//              → arr={5,10,20,30,?,?}, size=4


// ------------------------------------------------------------
// PART 5 — Optional helper (makes manual testing easier)
// ------------------------------------------------------------

// 5. Write void printArray(const int arr[], int size, const string& label)
//    Print:  label: [e1, e2, e3]
//    If size <= 0, print label: []
//    Use in main() to eyeball your shifts before you trust asserts.


// ------------------------------------------------------------
// PART 6 — Testing
// Uncomment one block at a time in runTests().
// ------------------------------------------------------------

void runTests() {
    // --- Part 1 ---
    int a[] = {10, 20, 30, 40};
    shiftLeftFrom(a, 4, 1);
    assert(a[0] == 10 && a[1] == 30 && a[2] == 40 && a[3] == 40);

    int b[] = {10, 20, 30};
    shiftRightFrom(b, 3, 1);
    assert(b[0] == 10 && b[1] == 20 && b[2] == 20 && b[3] == 30);

    // --- Part 2 ---
    int c[] = {10, 20, 30};
    int sz = 3;
    assert(removeAt(c, sz, 0) == true);
    assert(sz == 2 && c[0] == 20 && c[1] == 30);

    int d[5] = {10, 20};
    sz = 2;
    assert(appendValue(d, sz, 5, 30) == true);
    assert(sz == 3 && d[2] == 30);

    int e[5] = {20, 30};
    sz = 2;
    assert(prependValue(e, sz, 5, 10) == true);
    assert(sz == 3 && e[0] == 10 && e[1] == 20 && e[2] == 30);

    // --- Part 3 ---
    int f[] = {5, 5, 5};
    sz = 3;
    assert(removeFirst(f, sz, 5) == true);
    assert(sz == 2 && f[0] == 5 && f[1] == 5);

    int g[5] = {10, 20, 30};
    sz = 3;
    assert(insertAt(g, sz, 5, 1, 99) == true);
    assert(sz == 4 && g[0] == 10 && g[1] == 99 && g[2] == 20 && g[3] == 30);

    // --- Part 4 ---
    // int h[] = {5, 5, 10, 5};
    // sz = 4;
    // assert(removeAll(h, sz, 5) == 3);
    // assert(sz == 1 && h[0] == 10);

    // int i[6] = {10, 20, 40};
    // sz = 3;
    // assert(insertSorted(i, sz, 6, 25) == true);
    // assert(sz == 4 && i[0] == 10 && i[1] == 20 && i[2] == 25 && i[3] == 40);
}

int main() {
    // Start with Part 1. Use printArray in main() for quick visual checks:
    //
    //   int arr[] = {10, 20, 30};
    //   int sz = 3;
    //   printArray(arr, sz, "before");
    //   removeAt(arr, sz, 1);
    //   printArray(arr, sz, "after");

    runTests();
    cout << "All tests passed." << endl;
    return 0;
}
