//
// Created by polarnight on 24-7-31, 上午10:29.
//

#include <iostream>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  /* 此题同二叉树的最大深度 */
  int minDepth(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	if (!root) return 0;
	if (!root->left) return minDepth(root->right) + 1;
	if (!root->right) return minDepth(root->left) + 1;
	int left_depth = minDepth(root->left);
	int right_depth = minDepth(root->right);
	return min(left_depth, right_depth) + 1;
  }
};

int main() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_shared<gtn::TreeNodeShared>(3);
  root->left = std::make_shared<gtn::TreeNodeShared>(9);
  root->right = std::make_shared<gtn::TreeNodeShared>(20);
  root->right->left = std::make_shared<gtn::TreeNodeShared>(15);
  root->right->right = std::make_shared<gtn::TreeNodeShared>(7);

  Solution sol;
  cout << sol.minDepth(root) << endl;

  return 0;
}