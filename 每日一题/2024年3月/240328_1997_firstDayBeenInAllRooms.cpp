//
// Created by polarnight on 24-3-28, 下午2:11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*! \TLE */
    /*int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<int> count(n);
        count[0] = 1;

        int i = 0, ans = 0;
        while (i < n - 1) {
            int jude = count[i] % 2;
            if (jude != 0) {
                ans++;
                i = nextVisit[i];
                count[i]++;
                continue;
            }
            i = (i + 1) % 1000000007;
            count[i]++;
            ans++;
        }
        return ans;
    }*/

    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> dp(n);

        int mod = 1000000007;
        for (int i = 1; i < n; i++) {
            dp[i] = (2 * dp[i - 1] - dp[nextVisit[i - 1]] + 2 + mod) % mod;
        }
        return dp[n - 1];
    }
};

int main240328_1997() {
    vector<int> nextVisit = {0,0};

    Solution sol;
    cout << sol.firstDayBeenInAllRooms(nextVisit);

    return 0;
}