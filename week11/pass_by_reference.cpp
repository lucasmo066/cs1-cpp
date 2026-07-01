#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// ============================================================
// PASS BY REFERENCE — Week 11 (focused drill)
// Do AFTER array_functions_practice.
//
// Key ideas to nail before OOP:
//   - Pass-by-value: function gets a copy, original untouched.
//   - Pass-by-reference (int& x): function works with the original directly.
//   - const reference (const int& x): read-only access, no copy, no modify.
//   - int arr[] already passes array data by reference — size does NOT.
//     If you need the caller's size to change, pass int& size.
//
// Why this matters for OOP:
//   In CS2 every function that takes an object will use one of:
//     void modify(Player& p)        — changes the object
//     void display(const Player& p) — reads the object, no copy, no modify
//   You are building that muscle now with ints and arrays.
//
// Compile:
//   g++ -std=c++17 -Wall -o pass_by_reference pass_by_reference.cpp
// ============================================================

// ------------------------------------------------------------
// PART 1 — Single variable reference (core mechanics)
// ------------------------------------------------------------

// 1. Write void swap(int& a, int& b)
//    Exchange two ints in the caller's scope.
//    Hint: classic three-variable swap with a temp.
//    After: int x=3, y=7; swap(x,y); → x==7, y==3
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Write void doubleValue(int& n)
//    Multiply the caller's variable by 2 in place.
//    After: int x=5; doubleValue(x); → x==10
void doubleValue(int& n) {
    n *= 2;
}

// 3. Write void clampValue(int& n, int lo, int hi)
//    If n < lo set it to lo; if n > hi set it to hi; else leave it.
//    Example: clampValue(n, 0, 100) — keeps n in [0, 100].
//    Why this matters: you will write this exact pattern for parameter
//    validation in OOP (keeping a health bar between 0 and maxHealth, etc.)
void clampValue(int& n, int lo, int hi) {
    if (n < lo) {
        n = lo;
    } else if (n > hi) {
        n = hi;
    }
}

// 4. Write void sortTwo(int& a, int& b)
//    Leave a <= b — swap if needed.
//    After: int x=9, y=3; sortTwo(x,y); → x==3, y==9
void sortTwo(int& a, int& b) {
    if (b <= a) {
        swap(a,b);
    }
}

// ------------------------------------------------------------
// PART 2 — Multiple outputs from one function
// (The main reason pass-by-reference exists.)
// ------------------------------------------------------------

// 5. Write void findMinMax(int arr[], int size, int& minOut, int& maxOut)
//    Set minOut and maxOut to the min and max in one pass.
//    Defensive: if size < 1, print an error and return.
//    Note: one pass over the array is enough — update both in the same loop.
void findMinMax(int arr[], int size, int& minOut, int& maxOut) {
    if (size < 1) {
        cout << "Error: array is empty" << endl;
        return;
    }

    minOut = arr[0];
    maxOut = arr[0];

    // loop over the elements of the array
    for(int i = 1; i < size; i++) {
        //at every iteration check if the arr[i] is the new minOut or maxOut
        if (arr[i] < minOut) {
            minOut = arr[i];
        }
        if (arr[i] > maxOut) {
            maxOut = arr[i];
        }
    }
}

// 6. Write void splitEvenOdd(int arr[], int size, int& evenCount, int& oddCount)
//    Count how many elements are even and how many are odd.
//    Set both via reference — two outputs, one loop.
//    Defensive: if size <= 0, set both to 0 and return.
void splitEvenOdd (int arr[], int size, int& evenCount, int& oddCount) {
    if (size <= 0) {
        evenCount = 0;
        oddCount  = 0;
        return;
    }
    //initiate count
    evenCount = 0;
    oddCount  = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
}

// 7. Write void calcStats(int arr[], int size,
//                         int& outMin, int& outMax,
//                         double& outAvg)
//    Fill all three output parameters in one function call.
//    Caller declares the variables, passes them in, reads them after.
//    Defensive: if size < 1, print an error and return without writing
//    through the references (undefined values are safer than garbage).
//    This is the OOP constructor pattern — object receives data,
//    fills multiple internal fields in one call.

void calcStats(int arr[], int size, int& outMin, int& outMax, double& outAvg) {
    if (size < 1) {
        cout << "error: Array empty" << endl;
        return;
    }
    // One pass: seed from first element, then update min, max, and sum
    outMin = arr[0];
    outMax = arr[0];
    int sum = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < outMin) {
            outMin = arr[i];
        }
        if (arr[i] > outMax) {
            outMax = arr[i];
        }
        sum += arr[i];
    }
    // Cast before divide so average is not integer truncation
    outAvg = static_cast<double>(sum) / size;
}

// ------------------------------------------------------------
// PART 3 — Reference + array size changes
// ------------------------------------------------------------

// 8. Write bool removeFirst(int arr[], int& size, int target)
//    If target is found: shift elements left, decrement size, return true.
//    If not found: return false, size unchanged.
//    Example: arr={10,20,30}, size=3, target=20 → arr={10,30,?}, size=2
//    Defensive: if size <= 0, return false.
//    Why int& size: the caller's size variable must shrink — pass by value
//    would leave the caller's size untouched after the call.
bool removeFirst (int arr[], int& size, int target) {
    if (size <= 0) {
        return false;
    }

    for(int i = 0; i < size; i++) {
        if (arr[i] == target) {
         for (int j = i; j < size -1; j++) {
                 arr[j] = arr[j + 1];
           }
           size--;
           return true;    
        }
    }

    return false;
}

// 9. Write bool insertAt(int arr[], int& size, int capacity,
//                        int index, int value)
//    Shift elements right from index onward, insert value at index,
//    increment size, return true.
//    If size >= capacity (array full) or index out of range, return false.
//    Example: arr={10,20,30}, size=3, capacity=5, index=1, value=99
//             → arr={10,99,20,30,?}, size=4
//    Defensive: check size >= capacity AND index < 0 || index > size.

bool insertAt(int arr[], int& size, int capacity, int index, int value) {
    if (size >= capacity || index < 0 || index > size) {
        return false;
    }

    for (int j = size - 1; j >= index; j--) {
        arr[j + 1] = arr[j];
    }
    
    arr[index] = value;
    size++;
    return true;
}
// ------------------------------------------------------------
// PART 4 — const reference (read-only, no copy)
// ------------------------------------------------------------

// 10. Write void printArrayInfo(const int arr[], int size, const string& label)
//     Print:  <label>: [e1, e2, e3, ...]  (comma-space separated, brackets)
//     Example: printArrayInfo(data, 3, "scores") → scores: [10, 20, 30]
//     const string& label — no copy of the string, but cannot modify it.
//     This is the pattern for every display/print function in OOP.
//     Defensive: if size <= 0, print label + ": []"
void printArrayInfo(const int arr[], int size, const string& label) {
    cout << label << ": [";
    if (size <= 0) {
        cout << "]";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// 11. Write bool isSorted(const int arr[], int size)
//     Return true if arr is non-decreasing (each element >= previous).
//     const because we are only reading — should never modify.
//     Example: {1,2,2,5} → true    {1,3,2,5} → false
//     Defensive: size <= 1 → return true (0 or 1 element is trivially sorted)
bool isSorted(const int arr[], int size) {
    if (size <= 1) {
        return true;
    }

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

// ------------------------------------------------------------
// PART 5 — Think-about (no code required, write answer in comments)
// ------------------------------------------------------------

// 12. You have these two signatures:
//       void displayPlayer(Player p)
//       void displayPlayer(const Player& p)
//     Assume Player holds a name, team, and 20 stat fields.
//     a) Which version copies the object? Which doesn't?
//     b) Can either version modify the caller's Player?
//     c) Which would you use in production and why?
//     Write your answers as comments below.

// Answer 12a:
//   void displayPlayer(Player p) copies the whole Player object into the parameter.
//   void displayPlayer(const Player& p) does not copy — it aliases the caller's object.

// Answer 12b:
//   displayPlayer(Player p) cannot modify the caller's Player (only its local copy).
//   displayPlayer(const Player& p) also cannot modify the caller's Player because const
//   blocks changes through the reference.

// Answer 12c:
//   Use const Player& in production: no expensive copy of 20+ fields, and const makes
//   read-only intent clear to anyone reading or calling the function.


// 13. Why does removeFirst need int& size but findMinMax does NOT need
//     int& size? Write your reasoning as a comment.

// Answer 13:
//   removeFirst changes how many elements the caller considers valid — size must shrink
//   in the caller's scope, so we need int& size. findMinMax only reads the array and
//   writes min/max through separate out-parameters; it never changes the logical length.


void runTests() {
    int x = 3, y = 7;
    swap(x, y);
    assert(x == 7 && y == 3);

    int n = 5;
    doubleValue(n);
    assert(n == 10);
 
   int c = 150;
   clampValue(c, 0, 100);
   assert(c == 100);
 
    int a = 9, b = 3;
    sortTwo(a, b);
    assert(a == 3 && b == 9);
 
    int data[] = {4, -2, 9, 1, 7};
    int lo = 0, hi = 0;
    findMinMax(data, 5, lo, hi);
    assert(lo == -2 && hi == 9);

    int ev = 0, od = 0;
    splitEvenOdd(data, 5, ev, od);
    assert(ev == 2 && od == 3);

    int statMin = 0, statMax = 0;
    double statAvg = 0.0;
    calcStats(data, 5, statMin, statMax, statAvg);
    assert(statMin == -2 && statMax == 9 && statAvg == 3.8);

    int arr[] = {1, 2, 3};
    int sz = 3;
    assert(removeFirst(arr, sz, 2) == true);
    assert(sz == 2 && arr[0] == 1 && arr[1] == 3);

    int ins[5] = {10, 20, 30};
    sz = 3;
    assert(insertAt(ins, sz, 5, 1, 99) == true);
    assert(sz == 4 && ins[0] == 10 && ins[1] == 99 && ins[2] == 20 && ins[3] == 30);

    assert(isSorted(data, 5) == false);
    int sorted[] = {1, 3, 5, 7};
    assert(isSorted(sorted, 4) == true);
}

int main() {
    runTests();
    cout << "All tests passed." << endl;
    return 0;
}