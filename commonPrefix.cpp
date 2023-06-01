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
        unordered_set<char> hash_set;
        int ext = strs.size();
        int len = 0;
        string str = "";

        for (int i = 0; i < ext; i++) {
            len = strs[i].size();
            int cnt1 = str.size();
            string s = "";
            for (int j = 0; j < len; j++) {
                int cnt2 = 0;
                if (hash_set.find(strs[i][j]) == hash_set.end()) {
                    hash_set.insert(strs[i][j]);
                } else {
                    s += strs[i][j];
                    cnt2++;
                    if (cnt2 < str.size()) {
                        str = str.substr(0, cnt2);
                    }
                }
                if (j == 0) {
                    if (j == len - 1) {
                        str = s;
                        if (i != 0 && s == "") {
                            return s;
                        }
                    }
                }
            }
        }
        return str;
    }
};

int main14() {
    vector<string> strs = {"dog","racecar","car"};

    Solution sol;
    cout << sol.longestCommonPrefix(strs);
}