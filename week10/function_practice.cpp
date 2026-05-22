#include <iostream>
using namespace std;

// ============================================================
// FUNCTION PRACTICE — Week 10
// Work through each problem top to bottom.
// Write the function, then call it in main() to test it.
// ============================================================

// ------------------------------------------------------------
// LEVEL 1 — Basic functions, return types, parameters
// ------------------------------------------------------------

// 1. Write a function called square() that takes an int,
//    and returns that number multiplied by itself.
//    Call it in main() with a few different numbers and print the results.

int square(int number) {
    return number * number;
}

// 2. Write a function called celsiusToFahrenheit() that takes a double
//    representing a celsius temperature and returns the fahrenheit equivalent.
//    Formula: (celsius * 9.0 / 5.0) + 32.0
//    Call it in main() with 0, 100, and 37 and print each result.

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// 3. Write a void function called printFullName() that takes two strings,
//    a first name and a last name, and prints them on one line.
//    Example output: "Full name: Lucas Moraes"
//    Call it in main() with your own name.

void printFullName(string firstName, string lastName) {
    cout << "Full name: " << firstName << " " << lastName << endl;
}

// 4. Write a function called isEven() that takes an int
//    and returns a bool — true if the number is even, false if odd.
//    Hint: use the modulus operator %.
//    Call it in main() and print "even" or "odd" based on the result.

bool isEven(int inputNum) {
    return inputNum % 2 == 0;
}

// ------------------------------------------------------------
// LEVEL 2 — Functions with conditionals
// ------------------------------------------------------------

// 5. Write a function called getLetterGrade() that takes an int score
//    and returns a char representing the letter grade.
//    90-100 = A, 80-89 = B, 70-79 = C, 60-69 = D, below 60 = F
//    Call it in main() with at least 4 different scores and print each grade.

char getLetterGrade(int grade) {
    if (grade >= 90) {
        return 'A';
    } else if (grade >= 80) {
        return 'B';
    } else if (grade >= 70) {
        return 'C';
    } else if (grade >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// 6. Write a function called maxOfThree() that takes three ints
//    and returns the largest of the three.
//    Do not use any built in max() function — use if/else logic.
//    Call it in main() and verify it works.

int maxOfThree(int x, int y, int z) {
    int largest = x;

    if (y > largest) {
        largest = y;
    }
    if (z > largest) {
        largest = z;
    }

    return largest;
}

// 7. Write a function called calcShipping() that takes a double weight
//    and returns the shipping cost as a double.
//    Use these tiers:
//      under 1 lb  → $4.99
//      1 to 5 lbs  → $8.99
//      5 to 20 lbs → $14.99
//      over 20 lbs → $29.99
//    Call it in main() with a few different weights.

double calcShipping(double weight) {
    if (weight < 1) {
        return 4.99;
    } else if (weight < 5) {
        return 8.99;
    } else if (weight < 20) {
        return 14.99;
    } else {
        return 29.99;
    }
}

// ------------------------------------------------------------
// LEVEL 3 — Functions with loops
// ------------------------------------------------------------

// 8. Write a function called sumUpTo() that takes an int n
//    and returns the sum of all integers from 1 to n.
//    Example: sumUpTo(5) returns 15 (1+2+3+4+5)
//    Call it in main() with a few values.

int sumUpTo(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += i;
    }

    return result;
}

// 9. Write a function called printStars() that takes an int n
//    and prints a row of n stars on one line.
//    Example: printStars(4) prints ****
//    This is a void function.
//    Call it in main() with a few different values.

void printStars(int n) {
    string stars = "";

    for (int i = 0; i < n; i++) {
        stars += "*";
    }

    cout << stars << endl;
}

// 10. Write a function called countVowels() that takes a string
//     and returns the number of vowels in it (a e i o u, lowercase only).
//     Hint: loop through each character in the string using a for loop.
//     string length: str.length()
//     accessing a character: str[i]
//     Call it in main() with a few different words.

int countVowels(string inputWord) {
    int counter = 0;

    for (int i = 0; i < inputWord.length(); i++) {
        if (inputWord[i] == 'a' || inputWord[i] == 'e' || inputWord[i] == 'i'
            || inputWord[i] == 'o' || inputWord[i] == 'u') {
            counter++;
        }
    }

    return counter;
}

// ------------------------------------------------------------
// LEVEL 4 — Functions calling functions
// ------------------------------------------------------------

// 11. Write a function called printTemperatureReport() that takes
//     a double celsius temperature and prints a full report:
//       Celsius: 100.0
//       Fahrenheit: 212.0
//       Status: Boiling
//     Status rules (Fahrenheit): below 0 = Freezing, 0-99 = Normal, 100+ = Boiling
//     This function should CALL celsiusToFahrenheit() from problem 2
//     instead of redoing the math.
//     This is a void function.

void printTemperatureReport(double celsius) {
    double fahrenheit = celsiusToFahrenheit(celsius);
    string status;

    if (fahrenheit < 0) {
        status = "Freezing";
    } else if (fahrenheit <= 99) {
        status = "Normal";
    } else {
        status = "Boiling";
    }

    cout << "Celsius: " << celsius << endl;
    cout << "Fahrenheit: " << fahrenheit << endl;
    cout << "Status: " << status << endl;
}

// 12. Write a function called printOrderSummary() that takes a double weight
//     and a double itemPrice, and prints a short receipt:
//       Item price: $49.99
//       Weight: 3 lbs
//       Shipping: $8.99
//       Total: $58.98
//     CALL calcShipping() from problem 7 for shipping — do not redo the tier logic.
//     Total = itemPrice + shipping. This is a void function.
//     Call it in main() with a couple of weight/price pairs.

void printOrderSummary(double weight, double itemPrice) {
    double shippingCost = calcShipping(weight);
    double total = itemPrice + shippingCost;

    cout << "Item price: $" << itemPrice << endl;
    cout << "Weight: " << weight << " lbs" << endl;
    cout << "Shipping: $" << shippingCost << endl;
    cout << "Total: $" << total << endl;
}

// ------------------------------------------------------------
// main() — use this to test all your functions
// ------------------------------------------------------------

int main() {
    cout << "=== Level 1 ===" << endl;
    cout << "square(5): " << square(5) << endl;
    cout << "celsiusToFahrenheit(0): " << celsiusToFahrenheit(0) << endl;
    cout << "celsiusToFahrenheit(100): " << celsiusToFahrenheit(100) << endl;
    cout << "celsiusToFahrenheit(37): " << celsiusToFahrenheit(37) << endl;
    printFullName("Lucas", "Moraes");
    if (isEven(7)) {
        cout << "7 is even" << endl;
    } else {
        cout << "7 is odd" << endl;
    }

    cout << endl << "=== Level 2 ===" << endl;
    cout << "getLetterGrade(89): " << getLetterGrade(89) << endl;
    cout << "maxOfThree(4, 56, 32): " << maxOfThree(4, 56, 32) << endl;
    cout << "calcShipping(3): $" << calcShipping(3) << endl;

    cout << endl << "=== Level 3 ===" << endl;
    cout << "sumUpTo(10): " << sumUpTo(10) << endl;
    cout << "printStars(4): ";
    printStars(4);
    cout << "countVowels(\"hello\"): " << countVowels("hello") << endl;

    cout << endl << "=== Level 4 ===" << endl;
    printTemperatureReport(100);
    cout << endl;
    printOrderSummary(3, 49.99);
    cout << endl;
    printOrderSummary(55, 67.99);

    return 0;
}
