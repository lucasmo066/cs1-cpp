#include "logger.h"

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

static const char* LOG_FILE = "program.log";

// Convert LogLevel to the string shown in each log line.
static string levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:    return "DEBUG";
        case LogLevel::INFO:     return "INFO";
        case LogLevel::WARNING:  return "WARNING";
        case LogLevel::ERROR:    return "ERROR";
        case LogLevel::CRITICAL: return "CRITICAL";
        default:                 return "UNKNOWN";
    }
}

// Build a timestamp string using ctime (trim trailing newline).
static string currentTimestamp() {
    time_t now = time(nullptr);
    string stamp(ctime(&now));
    if (!stamp.empty() && stamp.back() == '\n') {
        stamp.pop_back();
    }
    return stamp;
}

// Format one log line: [timestamp] [LEVEL] message | context: ...
static string formatLogLine(const string& message, LogLevel level, const string& context) {
    string line = "[" + currentTimestamp() + "] [" + levelToString(level) + "] " + message;
    if (!context.empty()) {
        line += " | context: " + context;
    }
    return line;
}

// Write the same line to console and append to program.log.
static void outputLogLine(const string& line) {
    cout << line << endl;

    ofstream logFile(LOG_FILE, ios::app);
    if (logFile.is_open()) {
        logFile << line << endl;
    } else {
        cerr << "Failed to open " << LOG_FILE << " for writing." << endl;
    }
}

// --- Public API ---

void writeLogEntry(const string& message, LogLevel level, const string& context) {
    outputLogLine(formatLogLine(message, level, context));
}

void log(const string& message) {
    writeLogEntry(message);  // defaults: INFO level, no context
}

void log(const string& message, LogLevel level) {
    writeLogEntry(message, level);
}

void log(const string& message, LogLevel level, const string& context) {
    writeLogEntry(message, level, context);
}
