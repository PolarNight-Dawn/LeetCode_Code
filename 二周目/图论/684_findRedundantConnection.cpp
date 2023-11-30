#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 23-11-30, 下午3:12.
//

class Solution {
public:
    int nums = 1005;

    void init(vector<int> &father) {
        for (int i = 0; i < nums; i++) father[i] = i;
    }

    int find(vector<int> &father, int u) {
        return u == father[u] ? u : father[u] = find(father, father[u]);
    }

    bool IsSame(vector<int> &father, int u, int v) {
        u = find(father, u);
        v = find(father, v);
        return u == v;
    }

    void join(vector<int> &father, vector<int> &result, int u, int v) {
        u = find(father, u);
        v = find(father, v);
        if (u == v) return;
        father[u] = v;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> father(nums, 0);
        vector<int> result(2, 0);

        init(father);
        for (int i = 0; i < edges.size(); i++) {
            if (IsSame(father, edges[i][0], edges[i][1])) result[0] = edges[i][0], result[1] = edges[i][1];
            join(father, result, edges[i][0], edges[i][1]);
        }

        return result;
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2},
                                 {1, 3},
                                 {2, 3}};

    Solution sol;
    vector<int> result = sol.findRedundantConnection(edges);

    for (auto &res: result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}