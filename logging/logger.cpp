// logger.cpp — shared logging helpers for console output and program.log append.
#include "logger.h"

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

static const char* LOG_FILE = "program.log";
static LogLevel minLogLevel = LogLevel::DEBUG;

void setMinLogLevel(LogLevel minLevel) {
    minLogLevel = minLevel;
}

LogLevel getMinLogLevel() {
    return minLogLevel;
}

// True when this message should be written (level is at or above the floor).
static bool shouldLog(LogLevel level) {
    return static_cast<int>(level) >= static_cast<int>(minLogLevel);
}

// Map each LogLevel to a fixed-width label for formatted log lines.
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
    if (!shouldLog(level)) {
        return;
    }
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

void logDebug(const string& message, const string& context) {
    writeLogEntry(message, LogLevel::DEBUG, context);
}

void logInfo(const string& message, const string& context) {
    writeLogEntry(message, LogLevel::INFO, context);
}

void logWarning(const string& message, const string& context) {
    writeLogEntry(message, LogLevel::WARNING, context);
}

void logError(const string& message, const string& context) {
    writeLogEntry(message, LogLevel::ERROR, context);
}

void logCritical(const string& message, const string& context) {
    writeLogEntry(message, LogLevel::CRITICAL, context);
}

void clearLogFile() {
    ofstream logFile(LOG_FILE, ios::trunc);
    if (!logFile.is_open()) {
        cerr << "Failed to clear " << LOG_FILE << "." << endl;
    }
}

void logSessionBanner(const string& sessionName) {
    string rule(60, '-');
    writeLogEntry(rule, LogLevel::INFO);
    writeLogEntry("SESSION: " + sessionName, LogLevel::INFO);
    writeLogEntry(rule, LogLevel::INFO);
}

void logOperationReport(const string& operation,
                        bool success,
                        int stepsCompleted,
                        int stepsTotal,
                        const string& detail) {
    string context = "operation=" + operation;

    writeLogEntry("Operation started: " + operation, LogLevel::INFO, context);

    if (stepsTotal < 0) {
        writeLogEntry("Invalid stepsTotal — cannot compute progress",
                      LogLevel::ERROR,
                      context);
        writeLogEntry("Operation aborted: " + operation, LogLevel::ERROR, context);
        return;
    }

    if (stepsCompleted < 0) {
        stepsCompleted = 0;
    }
    if (stepsCompleted > stepsTotal) {
        stepsCompleted = stepsTotal;
    }

    int percent = 0;
    if (stepsTotal > 0) {
        percent = (stepsCompleted * 100) / stepsTotal;
    }

    writeLogEntry("Progress: " + to_string(stepsCompleted) + "/" + to_string(stepsTotal)
                      + " steps (" + to_string(percent) + "%)",
                  LogLevel::DEBUG,
                  context);

    if (!detail.empty()) {
        writeLogEntry("Detail: " + detail,
                      success ? LogLevel::INFO : LogLevel::WARNING,
                      context);
    }

    if (success) {
        if (stepsCompleted == stepsTotal && stepsTotal > 0) {
            writeLogEntry("Operation completed successfully: " + operation,
                          LogLevel::INFO,
                          context);
        } else {
            writeLogEntry("Operation finished early (partial success): " + operation,
                          LogLevel::WARNING,
                          context);
        }
    } else {
        writeLogEntry("Operation failed: " + operation, LogLevel::ERROR, context);
        if (stepsCompleted > 0) {
            writeLogEntry("Rolled back after " + to_string(stepsCompleted) + " completed step(s)",
                          LogLevel::WARNING,
                          context);
        }
    }
}

void logMetricBlock(const string& title,
                    const string metricNames[],
                    const int metricValues[],
                    int metricCount) {
    string rule(40, '=');
    writeLogEntry(rule, LogLevel::INFO);
    writeLogEntry("METRICS: " + title, LogLevel::INFO);

    if (metricCount <= 0) {
        writeLogEntry("No metrics provided", LogLevel::WARNING, "title=" + title);
        writeLogEntry(rule, LogLevel::INFO);
        return;
    }

    int sum = 0;
    int minValue = metricValues[0];
    int maxValue = metricValues[0];
    int zeroCount = 0;

    for (int i = 0; i < metricCount; i++) {
        int value = metricValues[i];
        sum += value;
        if (value < minValue) {
            minValue = value;
        }
        if (value > maxValue) {
            maxValue = value;
        }
        if (value == 0) {
            zeroCount++;
        }

        string row = "  " + metricNames[i] + " = " + to_string(value);
        LogLevel rowLevel = LogLevel::DEBUG;
        if (value < 0) {
            rowLevel = LogLevel::ERROR;
        } else if (value == 0) {
            rowLevel = LogLevel::WARNING;
        }
        writeLogEntry(row, rowLevel, "metric_index=" + to_string(i));
    }

    writeLogEntry("Metric count: " + to_string(metricCount), LogLevel::INFO, title);
    writeLogEntry("Sum: " + to_string(sum)
                      + " | min: " + to_string(minValue)
                      + " | max: " + to_string(maxValue),
                  LogLevel::INFO,
                  title);

    if (zeroCount > 0) {
        writeLogEntry("Zero-valued metrics: " + to_string(zeroCount),
                      LogLevel::WARNING,
                      title);
    }

    writeLogEntry(rule, LogLevel::INFO);
}

void summarizeLogFile() {
    ifstream inFile(LOG_FILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open " << LOG_FILE << " for reading." << endl;
        writeLogEntry("summarizeLogFile could not open log file",
                      LogLevel::ERROR,
                      string(LOG_FILE));
        return;
    }

    int totalLines = 0;
    int debugCount = 0;
    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;
    int criticalCount = 0;
    int otherCount = 0;
    string line;

    while (getline(inFile, line)) {
        totalLines++;
        if (line.find("[CRITICAL]") != string::npos) {
            criticalCount++;
        } else if (line.find("[ERROR]") != string::npos) {
            errorCount++;
        } else if (line.find("[WARNING]") != string::npos) {
            warningCount++;
        } else if (line.find("[INFO]") != string::npos) {
            infoCount++;
        } else if (line.find("[DEBUG]") != string::npos) {
            debugCount++;
        } else {
            otherCount++;
        }
    }
    inFile.close();

    string rule(50, '#');
    writeLogEntry(rule, LogLevel::INFO);
    writeLogEntry("LOG FILE SUMMARY: " + string(LOG_FILE), LogLevel::INFO);
    writeLogEntry("Total lines scanned: " + to_string(totalLines), LogLevel::INFO);
    writeLogEntry("DEBUG: " + to_string(debugCount), LogLevel::DEBUG);
    writeLogEntry("INFO: " + to_string(infoCount), LogLevel::INFO);
    writeLogEntry("WARNING: " + to_string(warningCount), LogLevel::WARNING);
    writeLogEntry("ERROR: " + to_string(errorCount), LogLevel::ERROR);
    writeLogEntry("CRITICAL: " + to_string(criticalCount), LogLevel::CRITICAL);

    if (otherCount > 0) {
        writeLogEntry("Unclassified lines: " + to_string(otherCount), LogLevel::WARNING);
    }

    int serious = warningCount + errorCount + criticalCount;
    if (serious == 0) {
        writeLogEntry("Health check: clean — no warnings or errors", LogLevel::INFO);
    } else if (criticalCount > 0 || errorCount > 0) {
        writeLogEntry("Health check: attention needed — " + to_string(serious)
                          + " warning/error/critical line(s)",
                      LogLevel::ERROR);
    } else {
        writeLogEntry("Health check: " + to_string(warningCount) + " warning(s) only",
                      LogLevel::WARNING);
    }

    writeLogEntry(rule, LogLevel::INFO);
}
