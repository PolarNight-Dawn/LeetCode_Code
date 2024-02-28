#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 24-2-27, 下午8:29.
//

const int n = 1e5;
bool is_prime[n + 1];
int init = []() {
    is_prime[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = true;
        }
    }
    return 0;
}();

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> bor(n + 1);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            bor[x].push_back(y);
            bor[y].push_back((x));
        }

        vector<int> size(n + 1);
        vector<int> nodes;
        function<void(int, int)> dfs = [&](int x, int father) {
            nodes.push_back(x);
            for (auto &y : bor[x]) {
                if (y != father && is_prime[y]) dfs(y, x);
            }
        };

        long long ans = 0;
        for (int x = 1; x <= n; x++) {
            if (is_prime[x]) continue;
            int sum = 0;
            for (auto &y : bor[x]) {
                if (!is_prime[y]) continue;
                if (size[y] == 0) {
                    nodes.clear();
                    dfs(y, -1);
                    for (auto &z : nodes)
                        size[z] = nodes.size();
                }
                ans += (long long) size[y] * sum;
                sum += size[y];
            }
            ans += sum;
        }
        return ans;
    }
};

int main2402272008() {
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};

    Solution sol;
    cout << sol.countPaths(n, edges);

    return 0;
}

