/**
 *
 *
 * author: tuoyu.zhang@gmail.com
 */

#ifndef _LOG_H_
#define _LOG_H_

#include <assert.h>
#include <iostream>
#include <map>
#include <vector>

class Log {
private:
  std::ostream *out;
  std::vector<std::string> header;
  std::map<std::string, double> default_value;
  std::map<std::string, double> value;
  bool open = false;

public:
  Log(std::ostream *stream) {
    out = stream;
    header.clear();
    default_value.clear();
    value.clear();
  }

  void log(const std::string &field, double d) { value[field] = d; }

  void init() {
    if (out != NULL) {
      for (uint i = 0; i < header.size(); i++) {
        *out << header[i];
        if (i < (header.size() - 1)) {
          *out << "\t";
        } else {
          *out << "\n";
        }
      }
      out->flush();

      for (uint i = 0; i < header.size(); i++) {
        value[header[i]] = default_value[header[i]];
      }
    } else {
      throw "Not Init output stream";
    }
  }

  void addField(const std::string &field, double dv) {
    std::vector<std::string>::iterator iter =
        std::find(header.begin(), header.end(), field);
    if (iter != header.end()) {
      throw "Field " + field + " Exsit already.";
    }
    header.push_back(field);
    value[field] = dv;
  }

  void newLine() {
    if (out != NULL) {
      for (uint i = 0; i < header.size(); i++) {
        *out << value[header[i]];
        if (i < (header.size() - 1)) {
          *out << "\t";
        } else {
          *out << "\n";
        }
      }
      out->flush();

      for (uint i = 0; i < header.size(); i++) {
        value[header[i]] = default_value[header[i]];
      }
    } else {
      throw "Not Init output stream";
    }
  }
};

#endif