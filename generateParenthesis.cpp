#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-5-17.
//

class Solution {
public:
    unordered_map<int, char> map = {{0, '{'},
                                    {1, '}'}};
    vector<string> res;

    string str = "{";

    void backTracking(string str, int left, int right, int index, int n) {
        int balance = left - right;
        if (index == 2 * n && balance == 0) {
            res.push_back(str);
            return;
        }

        if (balance < 0) {
            return;
        }

        for (int i = 0; i < 2; i++) {
            str.push_back(map[i]);
            if (i == 0) {
                left++;
                backTracking(str, left, right, index + 1, n);
                left--;
            }
            if (i == 1) {
                right++;
                backTracking(str, left, right, index + 1, n);
                right--;
            }
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        str.clear();
        res.clear();
        backTracking(str, 0, 0, 1, n);
        return res;
    }
};

int main22() {
    int n = 3;

    Solution sol;
    vector<string> vec = sol.generateParenthesis(n);

    for (string ch : vec) {
        cout << ch;
    }

    return 0;
}