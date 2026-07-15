#include "logger.h"

#include <iostream>

using namespace std;

int main() {
    clearLogFile();
    logSessionBanner("logging_demo");

    cout << "=== Logging system demo ===" << endl;
    cout << "Output goes to console and program.log (append mode)." << endl << endl;

    // One argument — INFO by default (overload 1).
    log("Application started");

    // Two arguments — specify level (overload 2).
    log("Cache warmed successfully", LogLevel::DEBUG);
    log("Disk space below 10%", LogLevel::WARNING);

    // Three arguments — level plus context (overload 3).
    log("Database connection failed", LogLevel::ERROR, "user_id:8823");
    log("Unhandled exception in payment module", LogLevel::CRITICAL, "order_id:44102");

    // Default parameters on writeLogEntry — omit level and/or context.
    writeLogEntry("Shutdown signal received");                         // INFO, no context
    writeLogEntry("Retrying connection", LogLevel::WARNING);           // WARNING, no context
    writeLogEntry("Request timed out", LogLevel::ERROR, "endpoint:/api/v1/users");

    cout << endl << "--- Level shortcuts ---" << endl;
    logDebug("Shortcut DEBUG line", "demo=shortcuts");
    logInfo("Shortcut INFO line");
    logWarning("Shortcut WARNING line");
    logError("Shortcut ERROR line", "module=payment");

    cout << endl << "--- Min log level filter (INFO and above) ---" << endl;
    setMinLogLevel(LogLevel::INFO);
    log("This DEBUG line is hidden", LogLevel::DEBUG);
    log("This INFO line still appears", LogLevel::INFO);
    log("Filter floor is INFO", LogLevel::INFO, "min_level=INFO");
    setMinLogLevel(LogLevel::DEBUG);

    cout << endl << "--- Operation reports ---" << endl;
    logOperationReport("sync_users", true, 10, 10, "All rows applied");
    logOperationReport("export_csv", false, 3, 8, "Disk full on step 4");

    cout << endl << "--- Metric block ---" << endl;
    string metricNames[] = {"requests", "errors", "retries", "cache_hits"};
    int metricValues[] = {120, 0, 4, 95};
    logMetricBlock("api_gateway", metricNames, metricValues, 4);

    cout << endl << "--- Log file summary ---" << endl;
    summarizeLogFile();

    cout << endl << "Done. Check program.log in this folder." << endl;
    return 0;
}
