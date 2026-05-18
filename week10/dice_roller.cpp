#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDie() {
    return (rand() % 6) + 1; 
}

int getHighest(int rolls[], int count) {
    int highest = rolls[0]; //assume the first one is zero then prove me wrong
    for (int i = 1; i < count; i++) {
        if (rolls[i] > highest) {
            highest = rolls[i];
        }
    }
    return highest;
}

int main() {
    srand(time(0));
    
    int numRolls;
    cout << "How many times do you want to roll? ";
    cin >> numRolls;
    
    int rolls[numRolls]; // creates an array that holds numRolls integers
    
    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDie();
        cout << "Roll " << i + 1 << ": " << rolls[i] << endl;
    }
    
    cout << "Highest roll: " << getHighest(rolls, numRolls) << endl;
    
    return 0;
}