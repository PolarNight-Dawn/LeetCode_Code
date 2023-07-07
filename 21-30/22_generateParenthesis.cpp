#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-5-17.
//

class Solution {
public:
    void backTracking(vector<string> &res, string &str, int left, int right, int n) {
        if (str.size() == 2 * n) {
            res.push_back(str);
            return;
        }

        if (left < n) {
            str.push_back('(');
            backTracking(res, str, left + 1, right, n);
            str.pop_back();
        }
        if (right < left) {
            str.push_back(')');
            backTracking(res, str, left, right + 1, n);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backTracking(res, str, 0, 0, n);
        return res;
    }
};

int main22() {
    int n = 3;

    Solution sol;
    vector<string> vec = sol.generateParenthesis(n);

    for (string ch: vec) {
        cout << ch;
    }

    return 0;
}
