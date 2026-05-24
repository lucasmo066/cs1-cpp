#include <iostream>
#include <string>
using namespace std;

// ============================================================
// LOOP PRACTICE — Week 10
// For every problem, before writing any code answer:
//   1. Starting state?
//   2. Condition — when do I stop?
//   3. What happens each pass? 
//   4. How do I progress?
// Write those answers as comments above each loop.
// ============================================================
// ------------------------------------------------------------
// PART 1 — Loop boundaries (< vs <=)
// The most common source of off-by-one errors
// ------------------------------------------------------------

// 1a. Print numbers 1 through 10 inclusive.
//     Expected output: 1 2 3 4 5 6 7 8 9 10
//     Question: should your condition be i < 10 or i <= 10? why?
    //This should be <= 10 since we are including 10. starting at 1, stop when i <= 10 (coudl be ==?), i++
        void printOneToTen() {
            for(int i = 1; i <= 10; i++) {
                cout << i << " ";
            }
        }

// 1b. Print numbers 0 through 9.
//     Expected output: 0 1 2 3 4 5 6 7 8 9
//     Question: should your condition be i < 10 or i <= 10? why?
//i <10. 
        void printZeroToNine() {
            for(int i = 0; i < 10; i++) {
                cout << i << " ";
            }
        }

// 1c. Print every even number from 2 to 20 inclusive.
//     Expected output: 2 4 6 8 10 12 14 16 18 20
//     Hint: what should i start at? what should i increment by?
        void evenTwoToTwenty() {
            for(int i = 2; i <= 20; i += 2) {
                cout << i << " ";
            }
        }

// 1d. Print numbers 10 down to 1 (countdown).
//     Expected output: 10 9 8 7 6 5 4 3 2 1
//     Hint: loops can count down too. what does the update look like?
        void countdownFromTen() {
            for(int i = 10; i >= 1; i--) {
                cout << i << " ";
            }
        }

// ------------------------------------------------------------
// PART 2 — Accumulation (building up a result)
// This is the pattern sumUpTo used.
// The key: result updates itself each pass using its own previous value.
// ------------------------------------------------------------

// 2a. Write a function called sumRange(int start, int end)
//     that returns the sum of all integers from start to end inclusive.
//     Example: sumRange(3, 7) = 3+4+5+6+7 = 25
//     Before writing: what is your starting state for result?
        //starting state is int start
//     What happens to result each pass?
        int sumRange(int start, int end) {
            int sum = 0;
            
            for(int i = start; i <= end; i++) {
                 sum += i;
            }

            return sum;
        }

// 2b. Write a function called factorial(int n)
//     that returns n! (n factorial).
//     Example: factorial(5) = 5*4*3*2*1 = 120
//     Hint: same accumulation pattern as sumUpTo but multiplication.
//     What should result be initialized to for multiplication? (not 0)
      int factorial (int n) {
            int resultFactorial = 1;
           
            for (int i = n; i >= 1; i--) {
                resultFactorial *= i;
            }

            return resultFactorial;
        }
// 2c. Write a function called countDown(int start)
//     that prints each number from start down to 1, then prints "Blast off!"
//     This is void — no return value needed.
//     Example: countDown(5) prints:
//       5
//       4
//       3
//       2
//       1
//       Blast off!

        void countdown(int start) {
            for(int i = start; i >= 1; i--) {
               cout << i << endl;
            }
            
            cout << "Blast Off!" << endl;
        }

// ------------------------------------------------------------
// PART 3 — Loops with conditions inside (filtering)
// Not every iteration does the same thing.
// ------------------------------------------------------------

// 3a. Write a function called sumEvens(int n)
//     that returns the sum of all even numbers from 1 to n.
//     Example: sumEvens(10) = 2+4+6+8+10 = 30
//     Hint: loop through all numbers, only add to result if the number is even.

       int sumEvens(int n) {
        int totalOfEvens = 0;

        for(int i = n; i >= 0; i -- ) { 
            if (i % 2 == 0) {
                totalOfEvens += i;
            }
        }


      
         return totalOfEvens;
    }

// 3b. Write a function called countNegatives(int arr[], int size)
//     that takes an array of ints and returns how many are negative.
//     Example: {3, -1, -4, 1, -5} returns 3
//     Hint: loop through the array, check each element.

// 3c. Write a function called findFirst(int arr[], int size, int target)
//     that returns the INDEX of the first occurrence of target in the array.
//     If target is not found, return -1.
//     Example: {10, 20, 30, 40} with target 30 returns index 2
//     This is called a linear search — you will see this constantly.


// ------------------------------------------------------------
// PART 4 — Nested loops
// A loop inside a loop. Inner loop completes fully for each outer iteration.
// ------------------------------------------------------------

// 4a. Print a rectangle of stars given a width and height.
//     printRectangle(4, 3) should print:
//       ****
//       ****
//       ****
//     Outer loop = rows, inner loop = stars per row.
//     Before writing: trace through manually.
//     When outer i=0, how many times does the inner loop run?

// 4b. Print a right triangle of stars given a height n.
//     printTriangle(4) should print:
//       *
//       **
//       ***
//       ****
//     Hint: on row i, print i stars.
//     The inner loop's condition depends on the outer loop's variable.

// 4c. Write a function called multiplicationTable(int n)
//     that prints an n x n multiplication table.
//     multiplicationTable(3) prints:
//       1  2  3
//       2  4  6
//       3  6  9
//     Hint: use setw(3) from <iomanip> to align columns.


// ------------------------------------------------------------
// PART 5 — While loops
// Use when you don't know ahead of time how many iterations you need.
// ------------------------------------------------------------

// 5a. Write a function called getPositiveInput()
//     that keeps asking the user for a number until they enter
//     a positive one, then returns it.
//     This is called an input validation loop — you will use this constantly.
//
//     int num;
//     cout << "Enter a positive number: ";
//     cin >> num;
//     while (???) {
//         cout << "Invalid. Try again: ";
//         cin >> num;
//     }
//     return num;

// 5b. Write a function called digitSum(int n)
//     that returns the sum of all digits in a number.
//     Example: digitSum(1234) = 1+2+3+4 = 10
//     Hint: use % 10 to get the last digit, / 10 to remove it.
//     Loop while n > 0.
//     Trace through manually first:
//       n=1234: last digit = 4, n becomes 123
//       n=123:  last digit = 3, n becomes 12
//       n=12:   last digit = 2, n becomes 1
//       n=1:    last digit = 1, n becomes 0
//       stop.

// 5c. Write a function called isPrime(int n)
//     that returns true if n is prime, false otherwise.
//     A prime number is only divisible by 1 and itself.
//     Hint: loop from 2 to n-1, check if any number divides n evenly.
//     If you find one that does, it is not prime — return false immediately.
//     If the loop finishes without finding one, return true.


// ------------------------------------------------------------
// main() — test each function as you complete it
// ------------------------------------------------------------

int main() {


    return 0;
}