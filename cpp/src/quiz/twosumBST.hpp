/**
 * LeetCode Problem 653
 *  Two Sum IV - Input is BST
 * 	https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * Author: tuoyu.zhang@gmail.com
 */

#ifndef _TWOSUM_BST_H_
#define _TWOSUM_BST_H_

#include <set>

#include "../core/executor.hpp"

struct TwoSumBST_TreeNode {
  int val;
  TwoSumBST_TreeNode *left;
  TwoSumBST_TreeNode *right;
};

class TwoSumBST : public Executor {

public:
  TwoSumBST(uint count, LogLevel level = LogLevel::INFO)
      : Executor(count, level) {
    addHeader(name());
  }
  ~TwoSumBST() {}

  void runImpl() { return; }

  std::string name() { return "twosum_bst"; }

  bool findTarget(TwoSumBST_TreeNode *root, int k) {
    std::set<int> set;
    return dfs(root, set, k);
  }

  bool dfs(TwoSumBST_TreeNode *root, std::set<int> set, int target) {
    if (root == NULL) {
      return false;
    }

    if (set.count(target - root->val)) {
      return true;
    } else {
      set.insert(target - root->val);
      return dfs(root->left, set, target) || dfs(root->right, set, target);
    }
  }
};

#endif