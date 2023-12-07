#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 23-12-7, 下午3:09.
//

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<pair<int, int>>> neighbors(connections.size() + 1);

        for (auto &city : connections) {
            neighbors[city[0]].push_back(make_pair(city[1], 1));
            neighbors[city[1]].push_back(make_pair(city[0], 0));
        }

        function<int(int, int)> DFS = [&](int x, int father) -> int {
            int ans = 0;
            for (auto &neighbor : neighbors[x]) {
                if (neighbor.first != father) {
                    ans += neighbor.second + DFS(neighbor.first, x);
                }
            }
            return ans;
        };
        return DFS(0, -1);
    }
};

int main1466() {
    int n = 6;
    vector<vector<int>> connections = {{0, 1},
                                       {1, 3},
                                       {2, 3},
                                       {4, 0},
                                       {4, 5}};

    Solution sol;
    cout << sol.minReorder(n, connections);

    return 0;
}