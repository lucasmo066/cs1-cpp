#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// ============================================================
// FUNCTION OVERLOADING DRILL — Week 11
//
// Goal: get comfortable choosing WHEN to overload vs when to use
// a single function with conditionals or default parameters.
// This skill shows up immediately in OOP — constructors are
// overloaded functions, and you will write them on day one of CS2.
//
// Rule of thumb:
//   Overload when:  input TYPES differ, or behavior diverges significantly
//   Default params: input types are the same, just optional trailing args
//   Single function: behavior difference is trivial (a style flag etc.)
//
// Compile:
//   g++ -std=c++17 -Wall -o overloading_drill overloading_drill.cpp
// ============================================================


// ------------------------------------------------------------
// PART 1 — Overload by parameter type
// Same concept, different input representations.
// ------------------------------------------------------------

// 1a. Write two overloads of printValue:
//       void printValue(int n)     → prints "int: 42"
//       void printValue(double n)  → prints "double: 3.14"
//       void printValue(string s)  → prints "string: hello"
//     Call: printValue(42), printValue(3.14), printValue("hello")
//     Compiler picks the right one based on argument type.


// 1b. Write two overloads of calcArea:
//       double calcArea(double side)              → square area (side * side)
//       double calcArea(double width, double height) → rectangle area
//     Example: calcArea(5.0) → 25.0
//              calcArea(4.0, 6.0) → 24.0
//     Note: same concept (area), different inputs.


// 1c. Write two overloads of describe:
//       void describe(int score)   → "Score: 95"
//       void describe(double gpa)  → "GPA: 3.85"
//       void describe(string name, int age) → "Name: Lucas, Age: 22"
//     Notice: the compiler cannot tell int from double apart
//     when you call describe(95) vs describe(3.85) unless you're explicit.
//     Test both: describe(95) and describe(3.85) and describe("Lucas", 22)


// ------------------------------------------------------------
// PART 2 — Overload by parameter count
// Classic OOP constructor pattern — you'll write these exact
// overloads for Player, BankAccount, etc. in CS2.
// ------------------------------------------------------------

// Imagine a simple Player struct (we'll use loose variables for now):
//   string name, string team, double batting_average

// 2a. Write three overloads of printPlayer:
//       void printPlayer(string name)
//           → "Player: Lucas"
//       void printPlayer(string name, string team)
//           → "Player: Lucas | Team: Rockies"
//       void printPlayer(string name, string team, double avg)
//           → "Player: Lucas | Team: Rockies | AVG: 0.285"
//     Each overload adds one more piece of information.
//     Note: could you solve this with default parameters instead?
//     Think about it — write your answer as a comment after the functions.


// 2b. Write two overloads of createGreeting:
//       string createGreeting(string name)
//           → "Hello, Lucas!"
//       string createGreeting(string name, string language)
//           → if language == "pt": "Olá, Lucas!"
//              if language == "es": "Hola, Lucas!"
//              else: "Hello, Lucas!"
//     Note: different parameter COUNT AND behavior — good overload candidate.


// ------------------------------------------------------------
// PART 3 — When NOT to overload (think-about, no code)
// ------------------------------------------------------------

// 3a. You want PrintDate to support two styles:
//       American: 7/30/2012
//       European: 30/7/2012
//     You could overload OR use a default parameter.
//     Which would you choose and why?
//     Write your answer as a comment.

// Answer 3a:


// 3b. You want a log() function that accepts a message, and optionally
//     a severity level (int), and optionally a context (string).
//     All three parameters have the same TYPE pattern: (string), (string, int),
//     (string, int, string). Would you overload or use default parameters?
//     Write your answer as a comment.

// Answer 3b:


// 3c. You want calcReturn() to work with:
//       calcReturn(double entryPrice, double exitPrice)
//       calcReturn(double prices[], int size)
//     Would you overload or use a single function?
//     What makes this a clear overload case vs the log() example?

// Answer 3c:


// ------------------------------------------------------------
// PART 4 — Overloading + default parameters combined
// This is the real-world pattern.
// ------------------------------------------------------------

// 4a. Write these overloads of formatScore:
//       string formatScore(int score)
//           → "Score: 95" (no padding)
//       string formatScore(int score, int maxScore)
//           → "Score: 95/100"
//       string formatScore(int score, int maxScore, string label)
//           → "Batting Average: 95/100"
//     The third overload extends the second — each one is a superset
//     of the previous. You'll write constructors exactly like this.


// 4b. Write printDate with a default parameter for printStyle:
//       void printDate(int day, int month, int year, int style = 0)
//     style 0 → month/day/year (American)
//     style 1 → day/month/year (European)
//     Then write a SEPARATE overload:
//       void printDate(int day, string monthName, int year)
//     Here the overload is justified because the type is genuinely different
//     (string month vs int month), not just optional.


// ------------------------------------------------------------
// PART 5 — Testing
// Uncomment one block at a time.
// ------------------------------------------------------------

// void runTests() {
//     assert(calcArea(5.0) == 25.0);
//     assert(calcArea(4.0, 6.0) == 24.0);
//
//     assert(createGreeting("Lucas") == "Hello, Lucas!");
//     assert(createGreeting("Lucas", "pt") == "Ola, Lucas!");
//     assert(createGreeting("Lucas", "es") == "Hola, Lucas!");
//
//     assert(formatScore(95) == "Score: 95");
//     assert(formatScore(95, 100) == "Score: 95/100");
//     assert(formatScore(95, 100, "Batting Average") == "Batting Average: 95/100");
// }

int main() {

    // Manual tests — call your functions and check output visually first
    // then move to assert-based runTests() above

    // printValue(42);
    // printValue(3.14);
    // printValue("hello");

    // printPlayer("Lucas");
    // printPlayer("Lucas", "Rockies");
    // printPlayer("Lucas", "Rockies", 0.285);

    // printDate(30, 7, 2012);        // uses default style=0
    // printDate(30, 7, 2012, 1);     // European style
    // printDate(30, "July", 2012);   // string overload

    return 0;
}