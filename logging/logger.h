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

#endif
