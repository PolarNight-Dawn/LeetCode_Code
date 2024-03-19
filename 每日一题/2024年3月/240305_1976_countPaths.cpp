//
// Created by polarnight on 24-3-5, 下午7:11.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths1976(int n, vector<vector<int>> &roads) {
        long long mod = 1000000007;
        vector<vector<long long>> group(n, vector<long long>(n, LLONG_MAX / 2));

        for (auto &r : roads) {
            int x = r[0], y = r[1], dis = r[2];
            group[x][y] = dis;
            group[y][x] = dis;
        }

        vector<long long> dis(n, LLONG_MAX / 2);
        vector<long long> f(n), done(n);
        dis[0] = 0, f[0] = 1;

        while (true) {
            int x = -1;
            for(int i = 0; i < n; i++) {
                if (!done[i] && (x < 0 || dis[i] < dis[x])) x = i;
            }

            if (x == n - 1) return f[n - 1];

            done[x] = true;
            for (int y = 0; y < n; y++) {
                long long new_dis = dis[x] + group[x][y];
                if (new_dis < dis[y]) {
                    dis[y] = new_dis;
                    f[y] = f[x];
                } else if (new_dis == dis[y]) {
                    f[y] = (f[y] + f[x]) % mod;
                }
            }
        }

    }
};

int main2403051976() {
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7},
                                 {0, 1, 2},
                                 {1, 2, 3},
                                 {1, 3, 3},
                                 {6, 3, 3},
                                 {3, 5, 1},
                                 {6, 5, 1},
                                 {2, 5, 1},
                                 {0, 4, 5},
                                 {4, 6, 2}};

    Solution sol;
    cout << sol.countPaths1976(n, roads);

    return 0;
}