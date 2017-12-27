/**
 *
 *
 */

#ifndef _BST_H_
#define _BST_H_

#include <cstdlib>
#include <vector>

namespace BST {
class BSTNode {
public:
  int value;
  BSTNode *left;
  BSTNode *right;

  BSTNode(int v, BSTNode *l = NULL, BSTNode *r = NULL)
      : value(v), left(l), right(r) {}

  ~BSTNode() {}
};

class BSTree {
public:
  BSTNode *generate(std::vector<int> list);
  BSTNode *generate(int *list, int sz);
  void destroy(BSTNode *root);
};

void BSTree::destroy(BSTNode *root) {
  if (root == NULL) {
    return;
  }

  if (root->left) {
    destroy(root->left);
  }

  if (root->right) {
    destroy(root->right);
  }
}

BSTNode *BSTree::generate(std::vector<int> list) {
  if (list.size() <= 0) {
    return NULL;
  }

  // generate BSTree as input array
  return NULL;
}

BSTNode *BSTree::generate(int *list, int sz) {
  if (list == NULL || sz <= 0) {
    return NULL;
  }

  // std::vector<int> array(list, sz);
  std::vector<int> array;
  for (int i = 0; i < sz; i++) {
    array.push_back(list[i]);
  }

  return BSTree::generate(array);
}

} // namespace BST

} // namespace BST

#endif