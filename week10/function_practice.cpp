#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
int square (int number) {
    return number * number;
}
// 2. Write a function called celsiusToFahrenheit() that takes a double
//    representing a celsius temperature and returns the fahrenheit equivalent.
//    Formula: (celsius * 9.0 / 5.0) + 32.0
//    Call it in main() with 0, 100, and 37 and print each result.
double celsiusToFahrenheit (double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// 3. Write a void function called printFullName() that takes two strings,
//    a first name and a last name, and prints them on one line.
//    Example output: "Full name: Lucas Moraes"
//    Call it in main() with your own name.
void printFullName (string firstName, string lastName) {
    cout << "Full name: " + firstName << " " << lastName << endl;
}

// 4. Write a function called isEven() that takes an int
//    and returns a bool — true if the number is even, false if odd.
//    Hint: use the modulus operator %.
//    Call it in main() and print "even" or "odd" based on the result.
bool isEven (int inputNum) {
    if (inputNum % 2 == 0) {
         return true;
    } else {
        return false;
    }
}
// ------------------------------------------------------------
// LEVEL 2 — Functions with conditionals
// ------------------------------------------------------------

// 5. Write a function called getLetterGrade() that takes an int score
//    and returns a char representing the letter grade.
//    90-100 = A, 80-89 = B, 70-79 = C, 60-69 = D, below 60 = F
//    Call it in main() with at least 4 different scores and print each grade.
 char getLetterGrade (int grade) {
    if (grade >= 90 ) {
        return 'A';
    } else if ( grade >= 80) {
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
int maxOfThree (int x, int y, int z) {
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
double calcShipping (double weight) {
    double shippingCost;

    if (weight < 1) {
        shippingCost = 4.99;
    } else if (weight < 5) {
        shippingCost = 8.99;

    } else if (weight < 20) {
        shippingCost = 14.99;

    } else {
        shippingCost = 29.99;
    }

    return shippingCost;
}

// ------------------------------------------------------------
// LEVEL 3 — Functions with loops
// ------------------------------------------------------------

// 8. Write a function called sumUpTo() that takes an int n
//    and returns the sum of all integers from 1 to n.
//    Example: sumUpTo(5) returns 15 (1+2+3+4+5)
//    Call it in main() with a few values.
int sumUpTo (int n) {


    for (x=0,x<i ,i++) {


    }
    
    return 0; 
}

// 9. Write a function called printStars() that takes an int n
//    and prints a row of n stars on one line.
//    Example: printStars(4) prints ****
//    This is a void function.
//    Call it in main() with a few different values.

// 10. Write a function called countVowels() that takes a string
//     and returns the number of vowels in it (a e i o u, lowercase only).
//     Hint: loop through each character in the string using a for loop.
//     string length: str.length()
//     accessing a character: str[i]
//     Call it in main() with a few different words.

// ------------------------------------------------------------
// LEVEL 4 — Functions calling functions
// ------------------------------------------------------------

// 11. Write a function called printTemperatureReport() that takes
//     a double celsius temperature and prints a full report:
//       Celsius: 100.0
//       Fahrenheit: 212.0
//       Status: Boiling
//     Status rules: below 0 = Freezing, 0-99 = Normal, 100+ = Boiling
//     This function should CALL celsiusToFahrenheit() from problem 2
//     instead of redoing the math.
//     This is a void function.

// 12. Write a function called rollDice() that takes an int numDice
//     and returns the total of rolling that many six sided dice.
//     It should call a helper function rollOne() that rolls a single die.
//     Call rollDice() in main() with 1, 2, and 3 dice and print each total.
//     Remember to seed srand() once in main().

// ------------------------------------------------------------
// main() — use this to test all your functions
// ------------------------------------------------------------

int main() {
    srand(time(0));
    
    // call and test each function here as you complete them

    //1.1
    //cout << square(5) << endl;

    //1.2 
    //cout << celsiusToFahrenheit(0) << endl;
    
    //1.3
   // printFullName("Lucas", "Moraes");

    //1.4
    //if (isEven(7)) {
   //     cout << "7 is even" << endl;
   // } else {
   //     cout << "7 is odd" << endl;
  //  }

    //2.1
  //  cout << getLetterGrade(89) << endl;

    //2.2
    //  cout << maxOfThree(4,56,32) << endl;
     //  cout << "also your mom is an absolute whore" << endl; 

     //2.3
    cout << "Shipping Cost: " << "$" << calcShipping(3) << endl;

    return 0;
}