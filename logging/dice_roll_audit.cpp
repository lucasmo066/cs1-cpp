// Dice rolling program that logs each roll and a face-frequency report.
//
// Compile & run (from logging/):
//   g++ -std=c++17 -Wall -o dice_roll_audit dice_roll_audit.cpp array_helpers.cpp logger.cpp
//   ./dice_roll_audit

#include "array_helpers.h"
#include "logger.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

const int MAX_ROLLS = 64;
const int DIE_FACES = 6;

int rollDie(int sides) {
    if (sides < 2) {
        logError("rollDie called with sides < 2", "sides=" + to_string(sides));
        return 1;
    }
    return (rand() % sides) + 1;
}

int rollMany(int rolls[], int count, int sides) {
    if (count <= 0) {
        logWarning("rollMany skipped — count must be positive",
                   "count=" + to_string(count));
        return 0;
    }
    if (count > MAX_ROLLS) {
        logWarning("rollMany clamped to MAX_ROLLS",
                   "requested=" + to_string(count) + " max=" + to_string(MAX_ROLLS));
        count = MAX_ROLLS;
    }

    for (int i = 0; i < count; i++) {
        rolls[i] = rollDie(sides);
        logDebug("Roll " + to_string(i + 1) + " = " + to_string(rolls[i]),
                 "sides=" + to_string(sides));
    }
    return count;
}

void countFaceFrequencies(const int rolls[], int count, int frequencies[]) {
    for (int face = 1; face <= DIE_FACES; face++) {
        frequencies[face - 1] = 0;
    }
    for (int i = 0; i < count; i++) {
        int value = rolls[i];
        if (value >= 1 && value <= DIE_FACES) {
            frequencies[value - 1]++;
        }
    }
}

void logRollSession(const int rolls[], int count, int sides) {
    logInfo("Dice session starting", "sides=" + to_string(sides));
    logArraySnapshot(rolls, count, "all-rolls", LogLevel::INFO);

    int frequencies[DIE_FACES];
    countFaceFrequencies(rolls, count, frequencies);

    string faceNames[] = {"face_1", "face_2", "face_3", "face_4", "face_5", "face_6"};
    logMetricBlock("die_face_counts", faceNames, frequencies, DIE_FACES);

    int low = arrayMin(rolls, count);
    int high = arrayMax(rolls, count);
    double avg = arrayAverage(rolls, count);

    logInfo("Lowest roll: " + to_string(low));
    logInfo("Highest roll: " + to_string(high));
    logInfo("Average roll: " + to_string(avg));

    if (arrayContains(rolls, count, sides)) {
        logInfo("Natural max face appeared at least once", "face=" + to_string(sides));
    } else {
        logWarning("No max-face rolls in this session", "face=" + to_string(sides));
    }

    if (arrayContains(rolls, count, 1)) {
        logDebug("At least one natural 1", "session=dice");
    }

    logOperationReport("dice_roll_session", true, count, count,
                       "Logged " + to_string(count) + " rolls on a d" + to_string(sides));
}

void demoFixedSession() {
    int rolls[MAX_ROLLS];
    int sides = 6;
    int requested = 12;

    logInfo("Demo: fixed 12 rolls of a d6");
    int actual = rollMany(rolls, requested, sides);
    logRollSession(rolls, actual, sides);
}

void demoTwoDiceSum() {
    int sums[MAX_ROLLS];
    int pairCount = 8;

    logInfo("Demo: eight rolls of two dice (sum each pair)");
    for (int i = 0; i < pairCount; i++) {
        int a = rollDie(6);
        int b = rollDie(6);
        sums[i] = a + b;
        logDebug("Pair " + to_string(i + 1) + ": " + to_string(a) + "+" + to_string(b)
                     + "=" + to_string(sums[i]),
                 "two_dice");
    }

    logArraySnapshot(sums, pairCount, "two-dice-sums", LogLevel::INFO);
    log(summarizeBatch("two-dice-sums", sums, pairCount), LogLevel::INFO);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    clearLogFile();
    logSessionBanner("dice_roll_audit");

    cout << "=== Dice roll audit ===" << endl << endl;

    demoFixedSession();
    demoTwoDiceSum();
    summarizeLogFile();

    cout << endl << "Done. See program.log for the full roll trail." << endl;
    return 0;
}
