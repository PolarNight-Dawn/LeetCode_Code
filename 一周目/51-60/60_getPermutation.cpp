#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-3.
//

class Solution {
public:
    int factors(int x) {
        int res = 1;
        for (int i = 1; i <= x; i++) {
            res *= i;
        }
        return res;
    }

    void backTracing(std::string &res, std::string &s, std::vector<int> &used, int cnt1, int n, int cnt2) {
        if (cnt1 == n) {
            if (cnt2 == 1) res = s;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (std::find(used.begin(), used.end(), i) != used.end()) continue;
            int fac = factors(n - used.size() - 1);
            if (cnt2 > fac) {
                cnt2 -= fac;
                continue;
            }
            s.push_back(i + '0');
            used.push_back(i);
            backTracing(res, s, used, cnt1 + 1, n, cnt2);
            used.pop_back();
            s.pop_back();
            if (res != "") return;
        }
    }

    std::string getPermutation(int n, int k) {
        std::string s;
        std::string res;
        std::vector<int> used;

        backTracing(res, s, used, 0, n, k);

        return res;
    }
};

int main60() {
    int n = 4;
    int k = 9;

    Solution sol;
    std::cout << sol.getPermutation(n, k);

    return 0;
}