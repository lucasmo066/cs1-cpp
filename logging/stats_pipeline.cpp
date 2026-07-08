// Multi-batch stats pipeline — scans arrays and logs a full report.
//
// Compile & run (from logging/):
//   g++ -std=c++17 -Wall -o stats_pipeline stats_pipeline.cpp array_helpers.cpp logger.cpp
//   ./stats_pipeline

#include "array_helpers.h"
#include "logger.h"

#include <iostream>
#include <string>

using namespace std;

struct BatchJob {
    string name;
    int values[16];
    int size;
    int warnThreshold;
    int criticalThreshold;
};

void logBatchSummary(const BatchJob& job) {
    logInfo("Pipeline received batch: " + job.name);

    if (job.size <= 0) {
        log("Rejected empty batch", LogLevel::WARNING, job.name);
        return;
    }

    string summary = summarizeBatch(job.name, job.values, job.size);
    log(summary, LogLevel::DEBUG, job.name);
    logArraySnapshot(job.values, job.size, job.name + "-snapshot", LogLevel::DEBUG);

    string csv;
    arrayToCsvLine(job.values, job.size, csv);
    log("Raw csv: " + csv, LogLevel::DEBUG, job.name);

    int belowWarn = countAtOrBelow(job.values, job.size, job.warnThreshold);
    int aboveCritical = countAboveValue(job.values, job.size, job.criticalThreshold);
    int inMidRange = countInRange(job.values, job.size, job.warnThreshold, job.criticalThreshold);

    log("At or below warn (" + to_string(job.warnThreshold) + "): " + to_string(belowWarn),
        LogLevel::INFO,
        job.name);
    log("Above critical (" + to_string(job.criticalThreshold) + "): " + to_string(aboveCritical),
        LogLevel::WARNING,
        job.name);
    log("In mid range: " + to_string(inMidRange), LogLevel::INFO, job.name);

    if (arrayContains(job.values, job.size, 0)) {
        log("Zero value present — flag for manual review", LogLevel::ERROR, job.name);
    }

    int minVal = arrayMin(job.values, job.size);
    int maxVal = arrayMax(job.values, job.size);
    if (maxVal - minVal > 80) {
        log("High spread detected: " + to_string(maxVal - minVal),
            LogLevel::WARNING,
            job.name);
    }

    if (arrayIsSorted(job.values, job.size)) {
        logDebug("Batch is sorted", job.name);
    } else {
        logWarning("Batch is not sorted", job.name);
    }

    writeLogEntry("Batch processing finished", LogLevel::INFO, job.name);
}

void runPipelineDemo() {
    BatchJob jobs[] = {
        {"east-wing",  {44, 52, 48, 0,  55, 49},       6,  20, 90},
        {"west-wing",  {12, 15, 18, 22, 19, 21, 17},    7,  20, 90},
        {"north-wing", {95, 98, 102, 97, 101, 99, 100},  7,  20, 90},
        {"south-wing", {},                               0,  20, 90},
        {"lab-retest", {3, 3, 3, 3, 3, 3, 3, 3},       8,  20, 90},
    };

    int jobCount = 5;
    log("Stats pipeline booting", LogLevel::INFO);
    log("Job count: " + to_string(jobCount), LogLevel::DEBUG);

    for (int i = 0; i < jobCount; i++) {
        logBatchSummary(jobs[i]);
    }

    log("Pipeline run complete", LogLevel::INFO);
}

int main() {
    clearLogFile();
    logSessionBanner("stats_pipeline");

    cout << "=== Stats pipeline ===" << endl << endl;
    runPipelineDemo();
    cout << endl << "Done. See program.log for details." << endl;
    return 0;
}
