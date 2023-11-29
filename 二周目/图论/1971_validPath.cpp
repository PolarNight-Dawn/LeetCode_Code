#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-29, 下午3:41.
//

class Solution {
public:
    int nums = 200005;
    //std::vector<int> father = std::vector<int> (nums, 0);

    void init(std::vector<int> &father) {
        for (int i = 0; i < nums; ++i) father[i] = i;
    }

    int find(int u, std::vector<int> &father) {
        return u == father[u] ? u : father[u] = find(father[u], father);
    }

    bool IsSame(int u, int v, std::vector<int> &father) {
        u = find(u, father);
        v = find(v, father);
        return u == v;
    }

    void join(int u, int v, std::vector<int> &father) {
        u = find(u, father);
        v = find(v, father);
        if (u == v) return;
        father[u] = v;
    }

    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        std::vector<int> father(nums, 0);
        init(father);
        for (int i = 0; i < edges.size(); i++) join(edges[i][0], edges[i][1], father);
        return IsSame(source, destination, father);
    }
};

int main() {
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0, destination = 2, n = 3;

    Solution sol;
    std::cout << sol.validPath(n, edges, source, destination);

    return 0;
}