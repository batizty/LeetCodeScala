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

#include "../utils/utils.hpp"

class Executor {
private:
  std::ostream *out;
  int running_count = 1;
  std::chrono::system_clock::time_point start = currentTimePoint();

public:
  virtual std::string name(void) = 0;

  virtual void runImpl(void) = 0;

  int setRunningCount(uint count) { return running_count = count; }

  Executor() { setStream(&std::cout); }

  void setStream(std::ostream *stream) { out = stream; }

  std::string header() { return ""; }

  std::string end() { return ""; }

  void summary() {
    std::chrono::system_clock::time_point now = currentTimePoint();

    std::chrono::duration<double> elapsed_seconds = now - start;

    *out << "  --- Summary ---\n";
    *out << "    Running Total Time : " +
                std::to_string(elapsed_seconds.count()) + "s\n";
    *out << "    Run Times          : " + std::to_string(running_count) + "\n";
    *out << "    Average Run Time   : " +
                std::to_string(elapsed_seconds.count() / running_count) + "s\n";
  }

  void run() {
    *out << " +++ Start " + name() + " Quiz +++\n";
    *out << header();

    if (running_count < 1) {
      throw "This Test Case Running Count" + std::to_string(running_count) +
          " Less than 1";
    }

    for (int i = 0; i < running_count; i++) {
      *out << "  + Start " + std::to_string(i) + "th/" +
                  std::to_string(running_count) + " run +\n";
      runImpl();
    }

    *out << end();

    summary();
  }
};

#endif