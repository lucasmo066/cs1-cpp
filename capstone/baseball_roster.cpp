#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;

// ============================================================
// BASEBALL ROSTER CAPSTONE — the "everything before OOP" project
//
// This is your capstone for Weeks 10-11. One longer program that
// uses ALL of it at once:
//   - functions (return values, void, functions calling functions)
//   - loops (traversal, search, nested, while-loop menu)
//   - arrays (fixed CAPACITY + logical size)
//   - pass-by-reference (int& size, out-parameters)
//   - const reference (read-only display functions)
//   - defensive programming (guard every function's inputs)
//
// THE DATA MODEL — parallel arrays:
//   Index i describes ONE player across three arrays:
//     names[i]   -> player's name   (string)
//     hits[i]    -> total hits      (int)
//     atBats[i]  -> total at-bats   (int)
//   Batting average is NOT stored — you compute it: hits / atBats.
//   'size' is how many players are actually on the roster right now
//   (the logical length), which is <= CAPACITY.
//
// WHY PARALLEL ARRAYS (read this — it's the whole point):
//   names, hits, and atBats always travel together. Every function
//   below has to pass all three. That is annoying on purpose: a
//   "player" is really ONE thing, but arrays force us to keep three
//   lists in sync by hand. In the next unit you'll bundle these into
//   a single Player object and the pain disappears. Feel the pain now
//   so OOP makes sense later.
//
// ============================================================
// HOW THIS FILE IS ORGANIZED (this is the .h / .cpp lesson)
//
//   Real C++ projects split code into:
//     roster.h    -> the PROTOTYPES (what functions exist)
//     roster.cpp  -> the DEFINITIONS (how they work)
//     main.cpp    -> the program that uses them
//
//   We are NOT splitting the file yet. Instead, we draw those exact
//   lines INSIDE one file, in this order:
//
//     SECTION 0 — HEADER PREVIEW : all your prototypes (future roster.h)
//     SECTION 1 — ROSTER ENGINE  : definitions, no I/O (future roster.cpp)
//     SECTION 2 — DISPLAY        : definitions that print (future display.cpp)
//     SECTION 3 — MENU / UI      : cin + the menu loop (future main.cpp)
//     SECTION 4 — runTests()     : asserts for the engine
//     SECTION 5 — main()         : wires it all together
//
//   When we split later, it becomes mostly copy-paste along these
//   boundaries. Keep each function in its section.
//
// DEFENSIVE POLICY for this file (stay consistent):
//   - bad size  -> return 0 / 0.0 / -1 / false (match the return type)
//   - atBats <= 0 -> batting average is 0.0 (never divide by zero)
//   - addPlayer REJECTS bad data instead of storing it
//   - the menu validates cin before doing anything
//
// COMPILE & RUN (from the capstone/ folder):
//   g++ -std=c++17 -Wall -o baseball_roster baseball_roster.cpp
//   ./baseball_roster
// ============================================================

// Shared roster capacity. Arrays never hold more players than this.
// (This one constant is given to you — everything else you write.)
const int CAPACITY = 25;


// ============================================================
// SECTION 0 — HEADER PREVIEW  (your future roster.h)
// ------------------------------------------------------------
// Write EVERY function prototype here, grouped by the section it
// will live in below. A prototype is just the function's first line
// ending in a semicolon (no body), e.g. the shape:
//     returnType functionName(parameterList);
//
// This block is literally what a header file is: a list of promises
// that these functions exist somewhere. Filling it in first forces
// you to decide each function's return type and parameters BEFORE
// you write the body — the same thinking a .h file demands.
//
// Group them with comment labels so the future split is obvious:
//   // --- roster engine (Section 1) ---
//   // --- display (Section 2) ---
//   // --- menu / UI (Section 3) ---
//
// Tip: come back and add each prototype the moment you decide on a
// function's signature below. Keep this list and the definitions in
// the same order.
// ============================================================




// ============================================================
// SECTION 1 — ROSTER ENGINE  (your future roster.cpp)
// Pure logic on the parallel arrays. NO cin, NO cout in this section
// (except where a prompt says otherwise). These are the functions
// runTests() will check.
// ============================================================

// 1a. battingAverage
//     Given a player's hits and atBats, return their batting average
//     as a double (hits divided by atBats).
//     Example: 3 hits in 10 at-bats -> 0.300
//     Watch out: this is a double. What happens with 3 / 10 in int
//     math? Cast before you divide.
//     Defensive: a player with atBats <= 0 hasn't batted yet ->
//     return 0.0 (never divide by zero).

// 1b. findPlayer
//     Search names[] for a target name. Return the INDEX of the
//     first match, or -1 if the name isn't on the roster.
//     This is the linear search from week10's findFirst — same idea,
//     with strings instead of ints. Almost every function below
//     starts by calling this to locate a player.
//     Defensive: size <= 0 -> return -1.

// 1c. addPlayer
//     Add a new player to the end of the roster.
//     Inputs: the three arrays, size BY REFERENCE (int& size),
//     the CAPACITY, and the new player's name, hits, and atBats.
//     Return true if added, false if rejected.
//     Reject (return false, change nothing) when:
//       - the roster is full (size >= capacity)
//       - hits or atBats is negative
//       - hits > atBats (impossible — you can't get more hits than
//         times you batted; this is a "bad row" we refuse to store)
//     On success: write name/hits/atBats at index 'size', then size++.
//     Why int& size: the caller's size must actually grow. Pass by
//     value and the caller would never see the new player.

// 1d. cutPlayer
//     Remove a player by name. Inputs: the three arrays, size BY
//     REFERENCE, and the name to cut. Return true if removed, false
//     if the name wasn't found.
//     This is week11's removeFirst, but you must shift ALL THREE
//     arrays left in lockstep so the rows stay aligned, then size--.
//     Trace it first: if you shift hits[] but forget names[], the
//     names and stats get out of sync — the classic parallel-array bug.
//     Defensive: size <= 0 -> return false.

// 1e. recordAtBats
//     A player had a game: add addHits and addAtBats to their totals.
//     Inputs: the three arrays, size, the player's name, addHits,
//     addAtBats. Find the player, then update hits[i] and atBats[i]
//     in place. Return true if updated, false if the name wasn't found.
//     (size does NOT change here — no int& needed for it.)
//     Defensive: reject negative addHits/addAtBats, or addHits >
//     addAtBats (same "bad row" rule as addPlayer) -> return false.

// 1f. teamAverage
//     Return the TEAM batting average as a double: total hits across
//     all players divided by total at-bats across all players.
//     (Not the average of each player's average — sum the raw hits and
//     raw at-bats first, then divide once.)
//     Accumulate with the sumArray pattern, twice (or in one loop).
//     Defensive: size <= 0, or total at-bats == 0 -> return 0.0.

// 1g. bestHitterIndex
//     Return the INDEX of the player with the highest batting average.
//     If more than one player ties, return the first.
//     This is week11's maxIndex, but you compare a COMPUTED value
//     (call battingAverage for each) instead of a stored array element.
//     Defensive: size <= 0 -> return -1.

// 1h. countAboveTeamAverage
//     Return how many players have a batting average strictly greater
//     than the team average.
//     Call teamAverage ONCE, store it, then loop (don't recompute the
//     team average every iteration). Same shape as countAboveAverage.
//     Defensive: size <= 0 -> return 0.

// 1i. sortByAverageDesc   *** NEW CONCEPT: selection sort ***
//     Sort the roster so the best hitters come first (highest batting
//     average at index 0, descending).
//     You have swapped two ints before (week11 swap) and reversed an
//     array in place. Sorting is that idea in a nested loop:
//
//       for each position i from 0 to size-1:
//         assume position i holds the best of what's left
//         inner loop j from i+1 to size-1:
//           if player j has a higher average than the current best,
//           remember j as the new best
//         swap position i with the best you found
//
//     THE PARALLEL-ARRAY CATCH: when you swap two players, you must
//     swap all THREE arrays at that pair of indices (names, hits,
//     atBats) so each row stays intact. Swapping only hits[] would
//     scramble who owns which stats.
//     Defensive: size <= 1 -> nothing to sort, just return.


// ============================================================
// SECTION 2 — DISPLAY  (your future display.cpp)
// Functions that print. Anything you only READ should come in as a
// const reference / const array — you promise not to modify it.
// Uses <iomanip>: fixed, setprecision(3), setw(n) for columns.
// ============================================================

// 2a. printPlayerLine
//     Print ONE player's line: their name, hits, atBats, and batting
//     average to 3 decimal places.
//     Inputs are read-only: take the name as a const string&, plus
//     the two ints. Reuse battingAverage — don't recompute the math.
//     Batting averages print like .300 / .275 — use fixed and
//     setprecision(3). Use setw(...) to line the columns up.
//     Example row:
//       Judge            62   187   0.332

// 2b. printRoster
//     Print the whole roster as a table: a header row (Name, Hits,
//     AB, AVG), then one line per player.
//     Take the arrays as const (const string names[], const int
//     hits[], const int atBats[]) plus size — you're only reading.
//     Loop over the players and call printPlayerLine for each so the
//     column formatting lives in exactly one place.
//     Defensive: size <= 0 -> print something like "Roster is empty."

// 2c. performanceTier
//     Given a batting average, return a string describing the tier:
//       avg >= 0.300 -> "All-Star"
//       avg >= 0.250 -> "Starter"
//       otherwise    -> "Bench"
//     This is week10's getLetterGrade shape (cascading if/else that
//     returns), just with doubles and strings.

// 2d. printTeamReport
//     Print a full team summary. Take the three arrays + size (const
//     where you only read). Include:
//       - the team batting average (call teamAverage)
//       - the best hitter's line (call bestHitterIndex, then
//         printPlayerLine for that index)
//       - how many players are above the team average
//         (call countAboveTeamAverage)
//       - each player's name and their performanceTier
//     This is the "functions calling functions" payoff — this report
//     is almost entirely calls to the functions you already wrote.
//     Defensive: size <= 0 -> print an error and return.


// ============================================================
// SECTION 3 — MENU / UI  (your future main.cpp)
// The only section that talks to the user with cin. Keep input
// handling here so the engine (Section 1) stays pure and testable.
// ============================================================

// 3a. printMenu
//     Print the numbered menu of actions the user can take, e.g.:
//       1) Add player
//       2) Cut player
//       3) Record at-bats for a player
//       4) Find a player
//       5) Print roster
//       6) Team report
//       7) Sort roster by average
//       0) Quit
//     Void function, just prints. Design the numbering to match how
//     you'll dispatch on the choice in main().

// 3b. getMenuChoice
//     Read the user's menu choice and return it as an int.
//     Reuse the input-validation-loop pattern from week10's
//     getPositiveInput: keep prompting until the number is a valid
//     menu option, then return it. (Optional stretch: also handle the
//     case where the user types letters instead of a number by
//     clearing cin — ask if you want to go there.)


// ============================================================
// SECTION 4 — runTests()  (correctness before you trust the menu)
// Build a small seeded roster in plain arrays and assert the engine
// functions behave. Uncomment / add asserts as you finish each one.
// ============================================================

// Write void runTests() that:
//   - declares a seeded roster, e.g.
//       string names[CAPACITY] = {"Judge", "Ohtani", "Rookie"};
//       int    hits[CAPACITY]  = {62, 54, 0};
//       int    atBats[CAPACITY]= {187, 180, 0};
//       int    size = 3;
//   - asserts the normal cases, for example:
//       battingAverage(62, 187) is about 0.331...  (compare with a
//         small tolerance, or check hits/atBats you control exactly,
//         since comparing doubles with == is fragile)
//       findPlayer(names, size, "Ohtani") == 1
//       findPlayer(names, size, "Nobody") == -1
//       teamAverage over the seed matches your hand calculation
//       bestHitterIndex(...) points at the top average
//   - asserts the DEFENSIVE cases (these are the ones that catch real
//     bugs):
//       battingAverage(5, 0) == 0.0            (the rookie, no at-bats)
//       findPlayer(names, 0, "Judge") == -1    (empty roster)
//       teamAverage(hits, atBats, 0) == 0.0
//       addPlayer rejects hits > atBats (returns false, size unchanged)
//       cutPlayer(names, hits, atBats, size, "Nobody") == false
//   - after a successful addPlayer/cutPlayer, assert size changed by
//     exactly 1 and the right row moved.
//   - Reminder: comparing two doubles with == can fail on rounding.
//     Prefer asserting on inputs you fully control, or check that the
//     difference from the expected value is tiny.


// ============================================================
// SECTION 5 — main()  (wire it together)
// ============================================================

// Write int main() that:
//   1. Declares the roster storage ONCE:
//        string names[CAPACITY];
//        int    hits[CAPACITY];
//        int    atBats[CAPACITY];
//        int    size = 0;              // start empty (or seed a few)
//   2. Calls runTests() first, so you never demo on broken engine code.
//      (Print "All tests passed." after it returns.)
//   3. Runs the menu loop:
//        - printMenu(); choice = getMenuChoice();
//        - a while loop that keeps going until the user chooses Quit
//        - dispatch on the choice (if/else or switch), calling the
//          matching function; read any extra input (name, hits, etc.)
//          right there in the handler, then pass it into the engine
//          function. Report success/failure using the bool each engine
//          function returns.
//   4. return 0;

int main() {
    // Roster storage — declared once, passed into every function.
    string names[CAPACITY];
    int hits[CAPACITY];
    int atBats[CAPACITY];
    int size = 0;   // start empty; grows as you addPlayer

    // TODO: call runTests(); here, then build the menu loop.

    return 0;
}

// ------------------------------------------------------------
// THE OOP BRIDGE (read once you have it all working):
//   Notice how every single function took names, hits, AND atBats,
//   and how sortByAverageDesc/cutPlayer had to move all three in
//   lockstep to avoid scrambling rows. That bookkeeping is exactly
//   what a class removes: bundle name+hits+atBats into one Player
//   type, give it a battingAverage() member, and functions pass ONE
//   Player instead of three arrays. After that, we split these
//   sections into roster.h / roster.cpp / main.cpp — the section
//   banners above are already the cut lines.
// ------------------------------------------------------------
