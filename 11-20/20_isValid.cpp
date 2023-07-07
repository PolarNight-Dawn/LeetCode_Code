#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;
//
// Created by polarnight on 23-5-14.
//

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {{'}', '{'},
                                         {')', '('},
                                         {']', '['}};
        stack<char> sta;

        for (auto &c: s) {
            if (map.count(c)) {
                if (sta.empty() || sta.top() != map[c]) {
                    return false;
                }
                sta.pop();
            } else {
                sta.push(c);
            }
        }
        return sta.empty();
    }
};

int main20() {
    string s = "(}";

    Solution sol;
    cout << sol.isValid(s);

    return 0;
}