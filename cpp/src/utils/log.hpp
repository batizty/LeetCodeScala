/**
 *
 *
 * author: tuoyu.zhang@gmail.com
 */

#ifndef _LOG_H_
#define _LOG_H_

#include <assert.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "utils.hpp"

enum LogLevel { INFO, DEBUG, ERROR };

class Log {
private:
  std::ostream *out;
  std::vector<std::string> header;
  char delimiter = '|';
  LogLevel level = LogLevel::INFO;
  std::map<LogLevel, std::string> levelPrefix;

public:
  Log(std::ostream *stream = &std::cout) {
    out = stream;
    levelPrefix[LogLevel::INFO] = "INFO";
    levelPrefix[LogLevel::DEBUG] = "DEBUG";
    levelPrefix[LogLevel::ERROR] = "ERROR";
  }

  LogLevel setLevel(LogLevel l) { return level = l; }
  char setDelimiter(char d) { return delimiter = d; }
  void addHeaders(std::vector<std::string> headers) { header = headers; }
  void addHeader(const std::string &h) { header.push_back(h); }
  void prefix() {
    // time part
    std::chrono::system_clock::time_point now = currentTimePoint();
    std::time_t now_t = std::chrono::system_clock::to_time_t(now);

    *out << std::put_time(std::localtime(&now_t), "%F %T");

    // header
    for (std::vector<std::string>::iterator iter = header.begin();
         iter != header.end(); iter++) {
      // for (auto hh : header) {
      *out << delimiter;
      *out << *iter;
    }

    *out << delimiter;
  }

  void output(const std::string &msg, const LogLevel level = LogLevel::INFO) {
    prefix();
    *out << levelPrefix[level] << delimiter << msg << "\n";
    out->flush();
  }

  // output info level message
  void info(const std::string &info) { output(info); }

  // output debug level message
  void debug(const std::string &debug) {
    if (level >= LogLevel::DEBUG) {
      output(debug, LogLevel::DEBUG);
    }
  }

  // output error level message
  void error(const std::string &err) {
    if (level >= LogLevel::ERROR) {
      output(err, LogLevel::ERROR);
    }
  }
};

#endif