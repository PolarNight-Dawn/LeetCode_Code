#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-4-23.
//

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int minLen = INT32_MAX;
        int minStr = 0;
        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].size();
            minLen = min(minLen, len);
            if (minLen == len) minStr = i;
        }

        string str = "";
        for (int j = 0; j < minLen; j++) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[minStr][j] != strs[i][j]) return str;
            }
            str += strs[minStr][j];
        }
        return str;
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};

    Solution sol;
    cout << sol.longestCommonPrefix(strs);
}