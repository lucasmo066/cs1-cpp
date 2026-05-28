#include <iostream>
#include <string>
using namespace std;

// ============================================================
// RECURSION WORKSHEET — Week 11 (do AFTER array_functions_practice)
//
// Write each function yourself under the prompt — signature and body.
// For EVERY problem: fill in the TRACE block in comments BEFORE you code.
//
// Compare to iterative factorial in week10/loop_practice.cpp (Part 2b).
//
// Defensive programming: invalid inputs are a separate base case BEFORE the
// recursive case (e.g. negative n → return -1, do not recurse).
//
// Compile:
//   g++ -std=c++17 -Wall -o recursion_worksheet recursion_worksheet.cpp
// ============================================================

// ------------------------------------------------------------
// HOW TO TRACE (copy this pattern above each function you write)
// ------------------------------------------------------------
//
//   factorial(4)
//     → 4 * factorial(3)
//         → 3 * factorial(2)
//             → 2 * factorial(1)
//                 → 1  ← base case, return 1
//             ← 2
//         ← 6
//     ← 24
//
// Answer in comments before coding:
//   1. What is the base case?
//   2. What gets SMALLER each call?
//   3. What do you return / do after the recursive call returns?
// ------------------------------------------------------------

// ------------------------------------------------------------
// PART A — Warm-up
// ------------------------------------------------------------

// A1. Write factorialRecursive(int n) — return n!
//     Example: factorialRecursive(5) → 120
//     Base case: n <= 1 → return 1
//     Recursive: return n * factorialRecursive(n - 1)
//     Defensive: if n < 0, return -1 (invalid; do not recurse).
//
// TRACE HERE (factorial(4)):
//


// A2. Write sumUpToRecursive(int n) — return 1 + 2 + ... + n
//     Example: sumUpToRecursive(5) → 15
//     Hint: sumUpTo(n) = n + sumUpTo(n - 1)
//
// TRACE HERE (sumUpToRecursive(4)):
//


// A3. Write powerRecursive(int base, int exp) — return base^exp (exp >= 0)
//     Example: powerRecursive(2, 5) → 32
//     Base: exp == 0 → return 1
//     Recursive: base * powerRecursive(base, exp - 1)
//     Defensive: if exp < 0, return -1.
//
// TRACE HERE (powerRecursive(2, 4)):
//


// ------------------------------------------------------------
// PART B — Arrays and strings (index parameter)
// Start calls from main() with index = 0.
// ------------------------------------------------------------

// B1. Write sumArrayRecursive(int arr[], int size, int index)
//     Return sum of arr[index] through arr[size - 1].
//     Example: {1,2,3}, size 3, index 0 → 6
//     Base: index >= size → return 0
//     Recursive: arr[index] + sumArrayRecursive(arr, size, index + 1)
//
// TRACE HERE:
//


// B2. Write countCharRecursive(string s, char target, int index)
//     Count how many times target appears from index onward.
//     Example: countCharRecursive("hello", 'l', 0) → 2
//     Base: index >= s.length() → return 0
//
// TRACE HERE:
//


// ------------------------------------------------------------
// PART C — Print / build
// ------------------------------------------------------------

// C1. Write void printRangeRecursive(int start, int end)
//     Print start through end inclusive, each with a space after.
//     Example: printRangeRecursive(1, 5) → 1 2 3 4 5
//     Base: start > end → return
//     Recursive: print start, then printRangeRecursive(start + 1, end)
//
// TRACE HERE (printRangeRecursive(1, 3)):
//


// C2. Write void printReverseRecursive(string s, int index)
//     Print characters from index to end in REVERSE (no endl).
//     Example: printReverseRecursive("cat", 0) → tac
//     Base: index >= length → return
//     Recursive: printReverseRecursive(s, index + 1); then cout << s[index];
//
// TRACE HERE:
//


// ------------------------------------------------------------
// PART D — Optional until A–C feel solid
// ------------------------------------------------------------

// D1. Write gcdRecursive(int a, int b) — greatest common divisor
//     Example: gcdRecursive(48, 18) → 6
//     Base: b == 0 → return a
//     Recursive: gcdRecursive(b, a % b)
//
// TRACE HERE:
//


// D2. Write fibRecursive(int n) — nth Fibonacci (fib(0)=0, fib(1)=1)
//     Example: fibRecursive(6) → 8
//
// TRACE HERE:
//


// ------------------------------------------------------------
// main() — test one function at a time as you finish each part
// ------------------------------------------------------------

int main() {

    // Examples to uncomment when ready:
    // cout << factorialRecursive(5) << endl;
    // cout << sumUpToRecursive(5) << endl;
    // cout << powerRecursive(2, 10) << endl;

    // int nums[] = {1, 2, 3, 4};
    // cout << sumArrayRecursive(nums, 4, 0) << endl;
    // cout << countCharRecursive("recursion", 'r', 0) << endl;

    // printRangeRecursive(1, 10);
    // cout << endl;
    // printReverseRecursive("hello", 0);
    // cout << endl;

    return 0;
}
