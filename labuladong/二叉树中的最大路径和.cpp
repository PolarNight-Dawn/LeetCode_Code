//
// Created by polarnight on 24-7-22, 上午11:27.
//

#include <iostream>
#include <climits>
#include <functional>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
													 right(right) {}
};

class Solution {
 public:
  int maxPathSum(TreeNode *root) {
	int res = INT_MIN;
	std::function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
	  if (!node)
		return 0;

	  int left = dfs(node->left);
	  int right = dfs(node->right);

	  res = std::max(res, node->val + left + right);
	  return std::max(node->val + std::max(left, right), 0);
	};

	dfs(root);

	return res;
  }
};

int main() {
  TreeNode *node = new TreeNode(2);
  node->left = new TreeNode(-1);
//   node->right = new TreeNode(3);

  Solution sol;
  std::cout << sol.maxPathSum(node) << std::endl;
}

