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
    cout << "  --- input ---" << endl;
    cout << "    input vector : ";
    outputVector(input);
    cout << "    input target : " + to_string(target) << endl;

    cout << "  --- result ---" << endl;
    vector<int> result = twoSum(input, target);
    if (!result.empty()) {
      cout << "    result vector : ";
      outputVector(result);
    } else {
      cout << "    no result" << endl;
    }
    return;
  }

  void outputVector(vector<int> &list) {
    if (list.size() > 0) {
      cout << "[";
      for (int i = 0; i < list.size(); i++) {
        cout << list[i];
        if (i != list.size() - 1) {
          cout << ", ";
        }
      }
      cout << "]";
      cout << endl;
    }
  }

  std::string name() { return "twosum"; }

  TwoSum() { init(); };
  TwoSum(uint count) {
    setRunningCount(count);
    init();
  }
  ~TwoSum(){};

  void init() { srand(time(NULL)); }

  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum == target) {
        cout << "number[" + to_string(l) + "](" + to_string(numbers[l]) +
                    ") "
                    " + "
                    "number[" +
                    to_string(r) + "](" + to_string(numbers[r]) +
                    ")"
                    " = target(" +
                    to_string(target) + ")"
             << endl;
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