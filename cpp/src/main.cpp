/**
 * author: tuoyu.zhang@gmail.com
 */

#include "quiz/twosum.hpp"
#include "quiz/twosumBST.hpp"
#include "utils/utils.hpp"

int main(int argc, char **argv) {
  TwoSum ts(100000);
  ts.run();

  TwoSumBST tsbst(100);
  tsbst.run();
  return 0;
}