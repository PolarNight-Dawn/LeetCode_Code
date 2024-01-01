#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-28, 下午5:39.
//

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int> &removable) {
        int n = s.size(), m = p.size();

        function<bool(int)> Check = [&](int k) -> bool {
            vector<int> state(n, 1);
            for (int i = 0; i < k; ++i){
                state[removable[i]] = 0;
            }

            int j = 0;
            for (int i = 0; i < n; ++i){
                if (state[i] && s[i] == p[j]){
                    ++j;
                    if (j == m) return true;
                }
            }
            return false;
        };

        int left = 0, right = removable.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

int main1898() {
    string s = "qobftgcueho";
    string p = "obue";
    vector<int> removable = {5, 3, 0, 6, 4, 9, 10, 7, 2, 8};

    Solution sol;
    cout << sol.maximumRemovals(s, p, removable);

    return 0;
}