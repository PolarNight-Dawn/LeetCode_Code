#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-16, 下午2:50.
//

class Solution {
public:
    void dfs(std::vector<std::vector<int>> &graph, int x, std::vector<std::vector<int>> &result, std::vector<int> &path) {
        if (x == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        for (auto y : graph[x]) {
            path.push_back(y);
            dfs(graph, y, result, path);
            path.pop_back();
        }
    }

    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;

        path.push_back(0);
        dfs(graph, 0, result, path);
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> graph = {{1, 2},
                                           {3},
                                           {3},
                                           {}};

    Solution sol;
    std::vector<std::vector<int>> res = sol.allPathsSourceTarget(graph);

    for (auto &tmp: res) {
        for (auto &vec: tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}