//
// Created by polarnight on 24-7-29, 上午10:10.
//

#ifndef LEEDCODE_INCLUDE_GENERATE_TREE_NODE_H_
#define LEEDCODE_INCLUDE_GENERATE_TREE_NODE_H_

#include <memory>

namespace generate_tree_node {
/* 原生指针版本，需要手动释放，容易泄露内存 */
struct TreeNodeRaw {
  int val;
  TreeNodeRaw *right;
  TreeNodeRaw *left;
  TreeNodeRaw() : val(0), right(nullptr), left(nullptr) {}
  explicit TreeNodeRaw(int x) : val(x), right(nullptr), left(nullptr) {}
  TreeNodeRaw(int x, TreeNodeRaw *right, TreeNodeRaw *left)
	  : val(x), right(right), left(left) {}
};

/* unique_ptr 版本
 * 自动管理其所拥有的对象的生命周期，在超出作用域时自动删除对象，避免了内存泄漏适用于
 * 适用于独占所有权的场景，需要通过 std::move 转移所有权 */
struct TreeNodeUnique {
  int val;
  std::unique_ptr<TreeNodeUnique> right;
  std::unique_ptr<TreeNodeUnique> left;
  TreeNodeUnique() : val(0), right(nullptr), left(nullptr) {}
  explicit TreeNodeUnique(int x) : val(x), right(nullptr), left(nullptr) {}
  TreeNodeUnique(int x, std::unique_ptr<TreeNodeUnique> right, std::unique_ptr<TreeNodeUnique> left)
	  : val(x), right(std::move(right)), left(std::move(left)) {}
};

/* shared_ptr 版本
 * 自动管理其所拥有的对象的生命周期，在超出作用域时自动删除对象，避免了内存泄漏
 * 适合在迭代中需要共享所有权的情况下使用 */
struct TreeNodeShared {
  int val;
  std::shared_ptr<TreeNodeShared> right;
  std::shared_ptr<TreeNodeShared> left;
  TreeNodeShared() : val(0), right(nullptr), left(nullptr) {}
  explicit TreeNodeShared(int x) : val(x), right(nullptr), left(nullptr) {}
  TreeNodeShared(int x, std::shared_ptr<TreeNodeShared> right, std::shared_ptr<TreeNodeShared> left)
	  : val(x), right(std::move(right)), left(std::move(left)) {}
};
};

namespace gtn = generate_tree_node;

#endif //LEEDCODE_INCLUDE_GENERATE_TREE_NODE_H_
