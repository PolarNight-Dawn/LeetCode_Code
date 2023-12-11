#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 23-12-5, 下午7:32.
//

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        vector<vector<int>> neighbors(roads.size() + 1);

        for (auto &road: roads) {
            neighbors[road[0]].push_back(road[1]);
            neighbors[road[1]].push_back(road[0]);
        }

        long long ans = 0;
        function<int(int, int)> DFS = [&](int x, int father) -> int {
            int size = 1;
            for (auto &neighbor: neighbors[x])
                if (neighbor != father)
                    size += DFS(neighbor, x);
            if (x)
                ans += (size - 1) / seats + 1;
            return size;
        };
        DFS(0, -1);
        return ans;
    }
};

int main2477() {
    vector<vector<int>> roads = {{0, 1},
                                 {0, 2},
                                 {0, 3}};
    int seats = 3;

    Solution sol;
    cout << sol.minimumFuelCost(roads, seats);

    return 0;
}
