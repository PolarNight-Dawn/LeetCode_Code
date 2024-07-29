//
// Created by polarnight on 24-7-29, 上午10:08.
//

#include <iostream>
#include <vector>
#include <memory>

#include "generate_tree_node.h"

using namespace std;

class Solution {
 public:
  vector<int> inorderTraversal(gtn::TreeNodeUnique* root) {

  }
};

int main01() {
  std::unique_ptr<gtn::TreeNodeUnique> root = std::make_unique<gtn::TreeNodeUnique>(1);
   root->right = std::make_unique<gtn::TreeNodeUnique>(2);
   root->right->left = std::make_unique<gtn::TreeNodeUnique>(3);


}

