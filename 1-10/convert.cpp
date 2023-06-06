#include <iostream>
#include <vector>

using namespace std;
//
// Created by polarnight on 23-4-13.
//

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1 || numRows > len) {
            return s;
        }

        vector<string> vec(numRows);
        int x = 0;
        int t = numRows * 2 - 2;
        for (int i = 0; i < len; ++i) {
            vec[x] += s[i];
            i % t < numRows - 1 ? ++x : --x;
        }

        string str;
        for (auto &ans: vec) {
            str += ans;
        }

        return str;
    }
};

int main06() {
    string s = "ABCDEF";
    int numRows = 2;

    Solution sol;
    cout << sol.convert(s, numRows);
}