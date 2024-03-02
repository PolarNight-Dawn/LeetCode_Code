//
// Created by polarnight on 24-3-2, 下午3:11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> neighbor(n);
        vector<int> is_restricted(n);

        for (auto &r : restricted)
            is_restricted[r] = 1;

        for (auto &e : edges) {
            neighbor[e[0]].push_back(e[1]);
            neighbor[e[1]].push_back(e[0]);
        }

        int ans = 0;
        function<void(int, int)> DFS = [&] (int x, int father) -> void {
            ans++;
            for (auto &y : neighbor[x]) {
                if (y != father && !is_restricted[y]) DFS(y, x);
            }
        };
        DFS(0, -1);
        return ans;
    }
};

int main2403022368() {
    int n = 7;
    vector<vector<int>> edges {{0, 1}, {1, 2}, {3, 1}, {4, 0}, {0, 5}, {5, 6}};
    vector<int> restricted = {4,5};

    Solution sol;
    cout << sol.reachableNodes(n, edges, restricted);

    return 0;
}