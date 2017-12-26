/**
 *
 *
 * author: tuoyu.zhang@gmail.com
 */

#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_

#include <assert.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "../utils/log.hpp"
#include "../utils/utils.hpp"

class Executor : public Log {
private:
  int running_count = 1;
  std::chrono::system_clock::time_point start = currentTimePoint();

public:
  virtual std::string name(void) = 0;

  virtual void runImpl(void) = 0;

  int setRunningCount(uint count) { return running_count = count; }

  Executor(uint count, LogLevel logLevel = LogLevel::INFO,
           std::ostream *stream = &std::cout)
      : Log(stream) {
    setRunningCount(count);
    setLevel(logLevel);
  }

  ~Executor() {}

  std::string header() { return ""; }

  std::string end() { return ""; }

  void summary() {
    std::chrono::system_clock::time_point now = currentTimePoint();

    std::chrono::duration<double> elapsed_seconds = now - start;

    info("  --- Summary ---");
    info("    Running Total Time : " + std::to_string(elapsed_seconds.count()) +
         "s");
    info("    Run Times          : " + std::to_string(running_count));
    info("    Average Run Time   : " +
         std::to_string(elapsed_seconds.count() / running_count) + "s");
  }

  void run() {
    info(" +++ Start " + name() + " Quiz +++");
    info(header());

    if (running_count < 1) {
      std::string err = "This Test Case Running Count" +
                        std::to_string(running_count) + " Less than 1";
      error(err);
      throw err;
    }

    for (int i = 0; i < running_count; i++) {
      debug("  + Start " + std::to_string(i) + "th/" +
            std::to_string(running_count) + " run +");
      runImpl();
    }

    info(end());

    summary();
  }
};

#endif