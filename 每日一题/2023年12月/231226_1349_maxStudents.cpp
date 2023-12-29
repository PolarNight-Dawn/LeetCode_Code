#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
//
// Created by polarnight on 23-12-26, 下午2:09.
//

class Solution {
public:
    int maxStudents(vector<vector<char>> &seats) {
        int m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n));

        for (int row = 1; row <= m; row++) {
            for (int s = 0; s < (1 << n); s++) {
                bitset<8> bs(s);
                bool ok = true;
                for (int j = 0; j < n; j++) {
                    if ((bs[j] && seats[row - 1][j] == '#') || (j < n - 1 && bs[j] && bs[j + 1])) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    dp[row][s] = -1;
                    continue;
                }
                for (int last = 0; last < (1 << n); last++) {
                    if (dp[row - 1][last] == -1) continue;
                    bitset<8> lbs(last);
                    bool flag = true;
                    for (int j = 0; j < n; j++) {
                        if (lbs[j] && ((j > 0 && bs[j - 1]) || (j < n - 1 && bs[j + 1]))) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) dp[row][s] = max(dp[row][s], dp[row - 1][last] + (int) bs.count());
                }
            }
        }
        int res = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (dp[m][i] > res) res = dp[m][i];
        }
        return res;
    }
};

int main231226() {
    vector<vector<char>> seats = {{'.', '#', '#', '.'},
                                  {'.', '.', '.', '#'},
                                  {'.', '.', '.', '.'},
                                  {'#', '.', '#', '#'}};

    Solution sol;
    cout << sol.maxStudents(seats);

    return 0;
}