//
// Created by polarnight on 24-7-30, 上午10:43.
//

#include <iostream>
#include <vector>
#include <queue>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  vector<double> averageOfLevels(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	queue<std::shared_ptr<gtn::TreeNodeShared>> que;
	vector<double> res;

	if (root) que.push(root);
	while (!que.empty()) {
	  int que_size = que.size();
	  long long sum = 0LL;

	  for (int i = 0; i < que_size; i++) {
		std::shared_ptr<gtn::TreeNodeShared> node = que.front();
		que.pop();
		sum += node->val;
		if (node->left) que.push(node->left);
		if (node->right) que.push(node->right);
	  }
	  res.push_back(sum / static_cast<double >(que_size));
	}
	return res;
  }
};

int main06() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_shared<gtn::TreeNodeShared>(3);
  root->left = std::make_shared<gtn::TreeNodeShared>(9);
  root->right = std::make_shared<gtn::TreeNodeShared>(20);
  root->right->left = std::make_shared<gtn::TreeNodeShared>(15);
  root->right->right = std::make_shared<gtn::TreeNodeShared>(7);

  Solution sol;
  auto res = sol.averageOfLevels(root);

  for (auto vec : res)
	cout << vec << " ";
  cout << endl;

  return 0;
}
