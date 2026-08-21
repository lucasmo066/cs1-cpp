#include <iostream>
#include <string>
using namespace std;

// ============================================================
// RECURSION DRILL — Week 11
//
// Goal: write recursive functions from scratch. Comment prompts
// only — no stubs. After this, move on to recursion_mini, then OOP.
//
// Recursion needs three things:
//   1. Base case — stop and return (or return early for bad input)
//   2. Smaller problem — an argument moves toward the base case
//   3. Combine / act — use the recursive result (or print before/after)
//
// Defensive programming: check invalid inputs BEFORE the recursive
// base case (separate early return).
//
// If you get stuck on one function, pencil a tiny call chain for that
// one input — then code. Do not write full traces for every problem.
//
// Compile:
//   g++ -std=c++17 -Wall -o recursion_worksheet recursion_worksheet.cpp
// ============================================================


// ------------------------------------------------------------
// PART 1 — Return-value recursion (classic pattern)
// ------------------------------------------------------------

// 1. factorialRecursive(int n) → return n!
//    Example: factorialRecursive(5) → 120
//    Base: n == 0 or n == 1 → return 1
//    Recursive: n * factorialRecursive(n - 1)
//    Defensive: n < 0 → return -1
//    (You already wrote an iterative factorial in week10/loop_practice.cpp.)
    int factorialRecursive (int n) {
        if (n < 0) return -1;

        if (n == 0 || n == 1) {
            return 1;
        }

        return n * factorialRecursive(n - 1);
    }


// 2. powerRecursive(int base, int exp) → return base^exp
//    Example: powerRecursive(2, 5) → 32
//    Base: exp == 0 → return 1
//    Recursive: base * powerRecursive(base, exp - 1)
//    Defensive: exp < 0 → return -1
int powerRecursive (int base, int exp) {
    if (exp < 0) return -1;

    return base^exp;
}


// ------------------------------------------------------------
// PART 2 — Index recursion (arrays and strings)
// Call from main() with index = 0.
// The index is the loop counter: grow it until you hit the end.
// ------------------------------------------------------------

// 3. sumArrayRecursive(int arr[], int size, int index)
//    Return sum of arr[index] through arr[size - 1].
//    Example: {1,2,3}, size=3, index=0 → 6
//    Base: index >= size → return 0
//    Recursive: arr[index] + sumArrayRecursive(arr, size, index + 1)



// 4. countCharRecursive(string s, char target, int index)
//    Count how many times target appears from index onward.
//    Example: countCharRecursive("hello", 'l', 0) → 2
//    Base: index >= s.length() → return 0
//    Recursive: (s[index] == target ? 1 : 0) + countCharRecursive(s, target, index + 1)



// ------------------------------------------------------------
// PART 3 — Void recursion (effect before vs after the call)
// ------------------------------------------------------------

// 5. printRangeRecursive(int start, int end)
//    Print start through end inclusive, space-separated (no endl).
//    Example: printRangeRecursive(1, 5) → 1 2 3 4 5
//    Base: start > end → return
//    Recursive: print start, then recurse with start + 1
//    (Printing happens going DOWN the stack.)



// 6. printReverseRecursive(string s, int index)
//    Print s in reverse from index onward (no endl).
//    Example: printReverseRecursive("cat", 0) → tac
//    Base: index >= s.length() → return
//    Key: recurse FIRST, then print s[index] — output on the way BACK UP.
//    Contrast with #5, where print happens before the recursive call.



// ------------------------------------------------------------
// PART 4 — Branching recursion
// ------------------------------------------------------------

// 7. fibRecursive(int n) — nth Fibonacci number
//    fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)
//    Example: fibRecursive(6) → 8
//    This makes TWO recursive calls per step (a branching tree).
//    Expensive (exponential time) — CS2 fixes this with memoization / DP.
//    Defensive: n < 0 → return -1



// ------------------------------------------------------------
// STRETCH — optional; do if Parts 1–4 feel solid
// ------------------------------------------------------------

// S1. binarySearchRecursive(int arr[], int low, int high, int target)
//     Return index of target in sorted arr, or -1 if not found.
//     Example: {1,3,5,7,9}, low=0, high=4, target=7 → 3
//     Base 1: low > high → return -1 (not found)
//     Base 2: arr[mid] == target → return mid
//     Recursive: search left half OR right half based on comparison
//     mid = (low + high) / 2
//     Each call eliminates half the remaining range (O(log n)).



// ------------------------------------------------------------
// main() — test one function at a time, uncomment as you go
// ------------------------------------------------------------

int main() {

    // Part 1
    // cout << factorialRecursive(5) << endl;   // 120
    // cout << factorialRecursive(0) << endl;   // 1
    // cout << factorialRecursive(-1) << endl;  // -1 (defensive)
    // cout << powerRecursive(2, 10) << endl;   // 1024
    // cout << powerRecursive(2, -1) << endl;   // -1 (defensive)

    // Part 2
    // int nums[] = {1, 2, 3, 4};
    // cout << sumArrayRecursive(nums, 4, 0) << endl;            // 10
    // cout << countCharRecursive("recursion", 'r', 0) << endl;  // 2

    // Part 3
    // printRangeRecursive(1, 10);
    // cout << endl;
    // printReverseRecursive("hello", 0);
    // cout << endl;

    // Part 4
    // cout << fibRecursive(6) << endl;   // 8
    // cout << fibRecursive(-1) << endl;  // -1 (defensive)

    // Stretch
    // int sorted[] = {1, 3, 5, 7, 9};
    // cout << binarySearchRecursive(sorted, 0, 4, 7) << endl;  // 3
    // cout << binarySearchRecursive(sorted, 0, 4, 4) << endl;  // -1

    return 0;
}
