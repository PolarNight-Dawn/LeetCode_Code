//
// Created by polarnight on 24-7-31, 上午10:15.
//

#include <iostream>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  /* 这里代码随想录将其归纳于层序遍历专题中，估计是出于寻求更多的练手的缘故
   * 采用层序遍历效率并不高，得到深度仅仅是层序遍历附带的结果，而对于这道题而言层序遍历的主要动作队列的进出反而是极大地浪费 */
  int maxDepth(const std::shared_ptr<gtn::TreeNodeShared>& root) {
	if (!root) return 0;
	int left_depth = maxDepth(root->left);
	int right_depth = maxDepth(root->right);
	return max(left_depth, right_depth) + 1;
  }
};

int main11() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_shared<gtn::TreeNodeShared>(3);
  root->left = std::make_shared<gtn::TreeNodeShared>(9);
  root->right = std::make_shared<gtn::TreeNodeShared>(20);
  root->right->left = std::make_shared<gtn::TreeNodeShared>(15);
  root->right->right = std::make_shared<gtn::TreeNodeShared>(7);

  Solution sol;
  cout << sol.maxDepth(root) << endl;

  return 0;
}