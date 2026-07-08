#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

#include <string>

enum class LogLevel;

int arraySum(const int arr[], int size);
double arrayAverage(const int arr[], int size);
int arrayMin(const int arr[], int size);
int arrayMax(const int arr[], int size);
bool arrayContains(const int arr[], int size, int target);
bool arrayIsSorted(const int arr[], int size);
int arrayCountValue(const int arr[], int size, int value);
int countAtOrBelow(const int arr[], int size, int threshold);
int countAboveValue(const int arr[], int size, int threshold);
int countInRange(const int arr[], int size, int low, int high);
void arrayToCsvLine(const int arr[], int size, std::string& out);
std::string summarizeBatch(const std::string& name, const int arr[], int size);
std::string formatArrayBracketed(const int arr[], int size, const std::string& label);
void logArraySnapshot(const int arr[], int size, const std::string& label, LogLevel level);

#endif
