#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 24-1-9, 下午2:50.
//

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
       int n = s.size();
       vector<int> dp(n + 1, INT32_MAX);
       unordered_map<string , int> map;

       for (auto &tmp : dictionary)
           map[tmp]++;

       dp[0] = 0;
       for (int i = 1; i <= n; i++) {
           dp[i] = dp[i - 1] + 1;
           for (int j = 0; j < i; j++) {
               if (map.count(s.substr(j, i - j))) dp[i] = min(dp[i], dp[j]);
           }
       }
        return dp[n];
    }
};

int main() {
    string s = "leetscode";
    vector<string> dictionary = {"leet","code","leetcode"};

    Solution sol;
    cout << sol.minExtraChar(s, dictionary);

    return 0;
}