//
// Created by polarnight on 24-2-29, 下午3:04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        vector<vector<int>> group(edges.size() + 1);
        for (auto &e : edges) {
            group[e[0]].push_back(e[1]);
            group[e[1]].push_back(e[0]);
        }

        unordered_set<long long> set;
        for (auto &g : guesses)
            set.insert((long long)g[0] << 32 | g[1]);

        int ans = 0, cnt_0 = 0;
        function<void(int, int)> DFS = [&](int x, int father) -> void {
            for (auto &y : group[x]) {
                if (y != father) {
                    cnt_0 += set.count((long long)x << 32 | y);
                    DFS(y, x);
                }
            }
        };
        DFS(0, -1);

        function<void(int, int, int)> ResetRoot = [&](int x, int father, int cnt) -> void {
            ans += cnt >= k;
            for (auto &y : group[x]) {
                if (y != father) {
                    ResetRoot(y, x, cnt + set.count((long long)y << 32 | x) - set.count((long long)x << 32 | y));
                }
            }
        };
        ResetRoot(0, -1, cnt_0);
        return ans;
    }
};

int main2402292581() {
    vector<vector<int>> edges = {{0,1},{2,0},{0,3},{4,2},{3,5},{6,0},{1,7},{2,8},{2,9},{4,10},{9,11},{3,12},{13,8},{14,9},{15,9},{10,16}
    };
    vector<vector<int>> guesses = {{8,2},{12,3},{0,1},{16,10}};
    int k = 2;

    Solution sol;
    cout << sol.rootCount(edges, guesses, k);

    return 0;
}