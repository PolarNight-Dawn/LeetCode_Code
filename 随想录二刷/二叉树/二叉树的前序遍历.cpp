//
// Created by polarnight on 24-7-28, 上午9:38.
//

#include <iostream>
#include <vector>
#include <stack>
#include <memory>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:

  /* 递归方法 */
  void BFS(std::unique_ptr<gtn::TreeNodeUnique> root, vector<int> &res) {
	if (!root) return;

	res.push_back(root->val);
	BFS(std::move(root->left), res);
	BFS(std::move(root->right), res);
  }

  vector<int> preorderTraversal(std::unique_ptr<gtn::TreeNodeUnique> root) {
	vector<int> res;
	BFS(std::move(root), res);
	return res;
  }

  /* 迭代方法 */
  vector<int> preorderTraversalIt(const std::shared_ptr<gtn::TreeNodeShared> &root) {
	stack<std::shared_ptr<gtn::TreeNodeShared>> sta;
	vector<int> res;

	if (!root) return res;
	sta.push(root);
	while (!sta.empty()) {
	  std::shared_ptr<gtn::TreeNodeShared> node = sta.top();
	  sta.pop();
	  res.push_back(node->val);
	  if (node->right) sta.push(node->right);
	  if (node->left) sta.push(node->left);
	}

	return res;
  }

  /* 在栈中使用原生指针进行迭代，同时保留 std::unique_ptr 用于管理节点的生命周期 */
  vector<int> preorderTraversalIt(std::unique_ptr<gtn::TreeNodeUnique> root) {
	stack<gtn::TreeNodeUnique *> sta;
	vector<int> res;

	if (!root) return res;
	sta.push(root.get());
	while (!sta.empty()) {
	  gtn::TreeNodeUnique *node = sta.top();
	  sta.pop();
	  res.push_back(node->val);
	  if (node->right) sta.push(node->right.get());
	  if (node->left) sta.push(node->left.get());
	}

	return res;
  }
};

int main01() {

  std::unique_ptr<gtn::TreeNodeUnique> root_unique = std::make_unique<gtn::TreeNodeUnique>(1);
  root_unique->right = std::make_unique<gtn::TreeNodeUnique>(2);
  root_unique->right->left = std::make_unique<gtn::TreeNodeUnique>(3);

  std::shared_ptr<gtn::TreeNodeShared> root_shared = std::make_shared<gtn::TreeNodeShared>(1);
  root_shared->right = std::make_unique<gtn::TreeNodeShared>(2);
  root_shared->right->left = std::make_unique<gtn::TreeNodeShared>(3);

  Solution sol;
  auto res_unique = sol.preorderTraversal(std::move(root_unique));
  auto res_shared = sol.preorderTraversalIt(root_shared);

  for (auto vec : res_unique)
	cout << vec << " ";
  cout << endl;

  for (auto vec : res_shared)
	cout << vec << " ";
  cout << endl;

  return 0;
}