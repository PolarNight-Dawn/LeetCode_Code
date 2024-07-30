//
// Created by polarnight on 24-7-29, 上午10:08.
//

#include <iostream>
#include <vector>
#include <memory>
#include <stack>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  /* 迭代 */
  vector<int> inorderTraversal(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	vector<int> res;
	stack<std::shared_ptr<gtn::TreeNodeShared>> sta;
	std::shared_ptr<gtn::TreeNodeShared> cur = root;
	while (cur != nullptr || !sta.empty()) {
	  if (cur != nullptr) {
		sta.push(cur);
		cur = cur->left;
	  } else {
		cur = sta.top();
		sta.pop();
		res.push_back(cur->val);
		cur = cur->right;
	  }
	}
	return res;
  }
};

int main02() {
  std::shared_ptr<gtn::TreeNodeShared> root = std::make_unique<gtn::TreeNodeShared>(1);
  root->right = std::make_shared<gtn::TreeNodeShared>(2);
  root->right->left = std::make_shared<gtn::TreeNodeShared>(3);

  Solution sol;
  auto res = sol.inorderTraversal(root);

  for (auto vec : res)
	cout << vec << " ";
  cout << endl;

  return 0;
}

