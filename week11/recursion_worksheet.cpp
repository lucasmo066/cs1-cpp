#include <iostream>
#include <string>
using namespace std;

// ============================================================
// RECURSION WORKSHEET — Week 11
//
// REQUIRED WORKFLOW — do not skip:
//   1. Read the problem.
//   2. Answer the three questions in the TRACE block (in comments).
//   3. Write the trace by hand (in comments) — follow the indented arrow format.
//   4. THEN write the code.
//   5. Test in main().
//
// Tracing is not optional. At a 6/10 comfort level on recursion, writing
// code without tracing first is the fastest way to get stuck.
//
// Defensive programming: invalid inputs are a separate base case BEFORE
// the recursive base case.
//
// Compile:
//   g++ -std=c++17 -Wall -o recursion_worksheet recursion_worksheet.cpp
// ============================================================

// ------------------------------------------------------------
// TRACE FORMAT — copy this pattern above every function
// ------------------------------------------------------------
//
//   factorialRecursive(4)
//     → 4 * factorialRecursive(3)
//         → 3 * factorialRecursive(2)
//             → 2 * factorialRecursive(1)
//                 → 1  ← base case
//             ← returns 2
//         ← returns 6
//     ← returns 24
//
// Three questions to answer before coding:
//   Q1. What is the base case? (when do I stop and return directly?)
//   Q2. What gets SMALLER each call? (how do I move toward the base case?)
//   Q3. What do I build / return on the way back up?
// ------------------------------------------------------------


// ------------------------------------------------------------
// PART A — Warm-up (required trace for all three)
// ------------------------------------------------------------

// A1. factorialRecursive(int n) → return n!
//     Example: factorialRecursive(5) → 120
//     Defensive: n < 0 → return -1
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE factorialRecursive(4):
//
// CODE:


// A2. sumUpToRecursive(int n) → return 1 + 2 + ... + n
//     Example: sumUpToRecursive(5) → 15
//     sumUpTo(n) = n + sumUpTo(n - 1)
//     Defensive: n < 0 → return -1
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE sumUpToRecursive(4):
//
// CODE:


// A3. powerRecursive(int base, int exp) → return base^exp
//     Example: powerRecursive(2, 5) → 32
//     Base case: exp == 0 → return 1
//     Defensive: exp < 0 → return -1
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE powerRecursive(2, 4):
//
// CODE:


// ------------------------------------------------------------
// PART B — Arrays and strings (index as the shrinking parameter)
// Call from main() with index = 0.
// The index is what gets larger each call — you reach the base case
// when index reaches the end. Same idea as the loop counter.
// ------------------------------------------------------------

// B1. sumArrayRecursive(int arr[], int size, int index)
//     Return sum of arr[index] through arr[size - 1].
//     Example: {1,2,3}, size=3, index=0 → 6
//     Base: index >= size → return 0
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE {1,2,3} from index 0:
//
// CODE:


// B2. countCharRecursive(string s, char target, int index)
//     Count how many times target appears from index onward.
//     Example: countCharRecursive("hello", 'l', 0) → 2
//     Base: index >= s.length() → return 0
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE "hello", target 'l', index 0:
//
// CODE:


// B3. maxArrayRecursive(int arr[], int size, int index)
//     Return the largest value from index onward.
//     Example: {3,9,1,5}, index=0 → 9
//     Base: index == size - 1 → return arr[index]  (one element left)
//     Recursive: compare arr[index] to maxArrayRecursive(arr, size, index+1)
//     Hint: use a helper like max(a, b) or just an if.
//     Defensive: size < 1 → return -1 before recursing.
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE {3,9,1} from index 0:
//
// CODE:


// ------------------------------------------------------------
// PART C — Print (no return value, effect happens going DOWN the stack)
// ------------------------------------------------------------

// C1. printRangeRecursive(int start, int end)
//     Print start through end inclusive, space-separated.
//     Example: printRangeRecursive(1, 5) → 1 2 3 4 5
//     Base: start > end → return
//     Recursive: print start, then recurse with start + 1
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE printRangeRecursive(1, 3):
//
// CODE:


// C2. printReverseRecursive(string s, int index)
//     Print s in reverse from index onward (no endl).
//     Example: printReverseRecursive("cat", 0) → tac
//     Base: index >= s.length() → return
//     Key: recurse FIRST, then print — output happens on the way BACK UP.
//     This is the difference from C1 where print happens going DOWN.
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:  ← think carefully: when does the printing happen here?
//
// TRACE "cat", index 0:
//
// CODE:


// ------------------------------------------------------------
// PART D — Harder problems (do after A-C feel solid)
// These are CS2 interview territory. Trace required.
// ------------------------------------------------------------

// D1. gcdRecursive(int a, int b) — greatest common divisor
//     Example: gcdRecursive(48, 18) → 6
//     Base: b == 0 → return a
//     Recursive: gcdRecursive(b, a % b)
//     Note: this one is hard to trace intuitively — do it anyway.
//     Understanding WHY a % b shrinks toward 0 is the insight.
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:
//
// TRACE gcdRecursive(48, 18):
//
// CODE:


// D2. fibRecursive(int n) — nth Fibonacci number
//     fib(0)=0, fib(1)=1, fib(n)=fib(n-1)+fib(n-2)
//     Example: fibRecursive(6) → 8
//     Note: this function makes TWO recursive calls per call.
//     Trace the full call tree for fibRecursive(4) — it branches.
//     This is expensive (exponential time) — we will fix this in CS2
//     with dynamic programming (memoization).
//
// ANSWER Q1:
// ANSWER Q2:
// ANSWER Q3:  ← what does combining two recursive results mean here?
//
// TRACE fibRecursive(4) — draw the full branching tree:
//
// CODE:


// D3. binarySearchRecursive(int arr[], int low, int high, int target)
//     Return index of target in sorted arr, or -1 if not found.
//     Example: {1,3,5,7,9}, low=0, high=4, target=7 → 3
//     Base 1: low > high → return -1 (not found)
//     Base 2: arr[mid] == target → return mid
//     Recursive: search left half OR right half based on comparison
//     Note: mid = (low + high) / 2
//     This is O(log n) — each call eliminates half the remaining elements.
//
// ANSWER Q1:
// ANSWER Q2:  ← what exactly is getting smaller here?
// ANSWER Q3:
//
// TRACE {1,3,5,7,9}, target=7:
//
// CODE:


// ------------------------------------------------------------
// main() — test one function at a time, uncomment as you go
// ------------------------------------------------------------

int main() {

    // Part A
    // cout << factorialRecursive(5) << endl;   // 120
    // cout << factorialRecursive(0) << endl;   // 1
    // cout << factorialRecursive(-1) << endl;  // -1 (defensive)
    // cout << sumUpToRecursive(5) << endl;     // 15
    // cout << powerRecursive(2, 10) << endl;   // 1024

    // Part B
    // int nums[] = {1, 2, 3, 4};
    // cout << sumArrayRecursive(nums, 4, 0) << endl;       // 10
    // cout << countCharRecursive("recursion", 'r', 0) << endl; // 2
    // cout << maxArrayRecursive(nums, 4, 0) << endl;       // 4

    // Part C
    // printRangeRecursive(1, 10);
    // cout << endl;
    // printReverseRecursive("hello", 0);
    // cout << endl;

    // Part D
    // cout << gcdRecursive(48, 18) << endl;   // 6
    // cout << fibRecursive(6) << endl;        // 8
    // int sorted[] = {1, 3, 5, 7, 9};
    // cout << binarySearchRecursive(sorted, 0, 4, 7) << endl;  // 3
    // cout << binarySearchRecursive(sorted, 0, 4, 4) << endl;  // -1

    return 0;
}