#ifndef LOGGER_H
#define LOGGER_H

#include <string>

// Five severity levels for filtering and display.
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

// Overloaded log() — pick the version that matches how much detail you have.
void log(const std::string& message);
void log(const std::string& message, LogLevel level);
void log(const std::string& message, LogLevel level, const std::string& context);

// Level shortcuts — same as log(message, LogLevel::X) with optional context.
void logDebug(const std::string& message, const std::string& context = "");
void logInfo(const std::string& message, const std::string& context = "");
void logWarning(const std::string& message, const std::string& context = "");
void logError(const std::string& message, const std::string& context = "");
void logCritical(const std::string& message, const std::string& context = "");

// Internal helper declared here so default parameters are visible at the call site.
// Callers in other translation units can use: writeLogEntry("msg") or
// writeLogEntry("msg", LogLevel::WARNING) and omit trailing arguments.
void writeLogEntry(const std::string& message,
                   LogLevel level = LogLevel::INFO,
                   const std::string& context = "");

// Drop messages below this level (default: show everything).
void setMinLogLevel(LogLevel minLevel);
LogLevel getMinLogLevel();

// Truncate program.log before a new demo run; writes a visible session header.
void clearLogFile();
void logSessionBanner(const std::string& sessionName);

// Multi-line report for a named operation: start, progress, result, detail.
void logOperationReport(const std::string& operation,
                        bool success,
                        int stepsCompleted,
                        int stepsTotal,
                        const std::string& detail = "");

// Write a titled block of metric name/value pairs (parallel arrays).
void logMetricBlock(const std::string& title,
                    const std::string metricNames[],
                    const int metricValues[],
                    int metricCount);

// Scan program.log, count lines by level, and write a summary report.
void summarizeLogFile();

#endif
