/**
 *
 *
 * author: tuouyu.zhang@gmail.com
 */

#ifndef _TWOSUM_H_
#define _TWOSUM_H_

#include <map>
#include <vector>

#include <cstdlib>
#include <ctime>

#include "../core/executor.hpp"

using namespace std;

class TwoSum : public Executor {
private:
  const int MAX_VALUE = 100;

public:
  void runImpl() {
    size_t size = randomSizeT();
    vector<int> input = generateInputVector(size);
    int target = generateInputTarget();
    debug("--- input ---");
    debug("    input vector : ");
    debug(outputVector(input));
    debug("    input target : " + to_string(target));

    debug("  --- result ---");
    vector<int> result = twoSum(input, target);
    if (!result.empty()) {
      debug("    result vector : ");
      debug(outputVector(result));
    } else {
      debug("    no result");
    }
    return;
  }

  std::string outputVector(vector<int> &list) {
    std::string msg = "";
    if (list.size() > 0) {
      msg += "[";
      for (int i = 0; i < list.size(); i++) {
        msg += std::to_string(list[i]);
        if (i != list.size() - 1) {
          msg += ", ";
        }
      }
      msg += "]";
    }
    return msg;
  }

  std::string name() { return "twosum"; }

  TwoSum() : Executor(1) { init(); };
  TwoSum(uint count, LogLevel level = LogLevel::INFO) : Executor(count, level) {
    init();
    addHeader(name());
  }
  ~TwoSum(){};

  void init() { srand(time(NULL)); }

  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum == target) {
        debug("number[" + to_string(l) + "](" + to_string(numbers[l]) +
              ") "
              " + "
              "number[" +
              to_string(r) + "](" + to_string(numbers[r]) +
              ")"
              " = target(" +
              to_string(target) + ")");
        return vector<int>{l + 1, r + 1};
      } else if (sum > target) {
        r--;
      } else {
        l++;
      }
    }
    return vector<int>{};
  }

  int randomSizeT() { return rand() % MAX_VALUE + 3; }

  vector<int> generateInputVector(size_t n) {
    assert(n >= 3);
    vector<int> list;
    for (int i = 0; i < n; i++) {
      list.push_back(rand() % MAX_VALUE);
    }
    return list;
  }

  int generateInputTarget() { return rand() % MAX_VALUE; }
};

#endif