#include <iostream>
#include <string>
#include <iomanip>
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

        for(int i = n; i >= 1; i -- ) { 
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
    int countNegatives(int arr[], int size) {
        int negativeValues = 0;

        for (int i = 0; i < size; i++) {
            if (arr[i] < 0) {
                negativeValues++;
            }
        }
        
        return negativeValues;
    }

// 3c. Write a function called findFirst(int arr[], int size, int target)
//     that returns the INDEX of the first occurrence of target in the array.
//     If target is not found, return -1.
//     Example: {10, 20, 30, 40} with target 30 returns index 2
//     This is called a linear search — you will see this constantly.
    int findFirst (int arr[], int size, int target) {
        int IndexFirstOccur = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                IndexFirstOccur = i;
                break;
            }
        }

        return IndexFirstOccur;
    }

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
        void printRectangle (int width, int height) {
            for (int row = 0; row < height; row++ ) {
                for (int col = 0; col < width; col++) {
                    cout << '*';
                }
                cout << endl;
            }
        }

// 4b. Print a right triangle of stars given a height n.
//     printTriangle(4) should print:
//       *
//       **
//       ***
//       ****
//     Hint: on row i, print i stars.
//     The inner loop's condition depends on the outer loop's variable.
        void printTriangle (int n) {
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < row; col++) { 
                    cout << '*'; 
                }
                cout << endl;
            }
        }

// 4c. Write a function called multiplicationTable(int n)
//     that prints an n x n multiplication table.
//     multiplicationTable(3) prints:
//       1  2  3
//       2  4  6
//       3  6  9
//     Hint: use setw(3) from <iomanip> to align columns.
        void multiplicationTable(int n) {
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    cout << setw(3) << (row + 1) * (col + 1);
                }
                cout << endl;
            }
        }

// ------------------------------------------------------------
// PART 4 EXTRA — More nested loop practice (E1–E6)
// For each: write outer/inner four-question comments, trace ONE row, then code.
// Suggested order: E2, E3, E4, E1, E6, E5
// ------------------------------------------------------------
// E1. Write void printHollowRectangle(int width, int height)
//     Print a hollow rectangle of stars (border only).
//     printHollowRectangle(5, 4) should print:
//       *****
//       *   *
//       *   *
//       *****
//     Outer = rows, inner = columns (visit every cell).
//     Print '*' on first/last row OR first/last column; otherwise print a space.
//     Hint: inside the inner loop, use if with row and col (both matter).
        void printHollowRectangle (int width, int height) {
            for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                    if ( col == 0 || col == width - 1 || row == 0 || row == height - 1) {
                        cout << '*';
                    } else {
                        cout << ' ';
                    }
                }
               cout << endl; 
            }
        }

        

// E2. Write void printNumberTriangle(int n)
//     Same nested structure as printTriangle, but print digits.
//     printNumberTriangle(4) should print:
//       1
//       12
//       123
//       1234
//     Hint: inner bound grows with row (row + 1 times). Print col + 1 if row starts at 0.

        void printNumberTriangle (int n) {
            for (int row = 0; row < n; row++ ) {
                for (int col = 0; col < row + 1; col++) {
                    cout << col + 1 <<' ';
                }
                cout << endl;
            }
        }

// E3. Write void printInvertedTriangle(int n)
//     Stars decrease each row (opposite of printTriangle).
//     printInvertedTriangle(4) should print:
//       ****
//       ***
//       **
//       *
//     Before coding: on row 0, how many stars? on row 3?
//     Hint: inner bound shrinks with row (e.g. n - row times when row starts at 0).

        void printInvertedTriangle (int n) {
            for (int row = 0; row < n; row++) {
                //keep going while col is less than (n-row)
                for (int col = 0; col < n - row; col++) {
                    cout << '*';
                }
                cout << endl;
            }
        }

// E4. Write int sumGrid(int n)
//     Treat an n x n grid where each cell value is (row + 1) * (col + 1)
//     (same values as the multiplication table). Return the sum of all cells.
//     sumGrid(3) = 1+2+3 + 2+4+6 + 3+6+9 = 36
//     Outer = rows, inner = cols. No cout — accumulate with += (like sumRange).
        int sumGrid (int n) {
            int sumOfCells = 0;

            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                   sumOfCells += (row + 1) * (col + 1);
                }
            }

            return sumOfCells;
        }


// E5. Write int countStarsInTriangle(int n)
//     How many '*' does printTriangle(n) print in total?
//     countStarsInTriangle(4) = 1+2+3+4 = 10
//     Use nested loops to count (or solve with math after you see the pattern).

// E6. Write void printCheckerboard(int size)
//     Print a size x size checkerboard with '#' and spaces.
//     printCheckerboard(4) should print:
//       # #
//        #
//       # #
//        #
//     Hint: nested loops over row/col; print '#' when (row + col) % 2 == 0, else ' '.
//     Use endl once per row (after the inner loop).

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

 printHollowRectangle(5,6);

    return 0;
}