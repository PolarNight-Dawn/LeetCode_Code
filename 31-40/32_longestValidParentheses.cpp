#include <iostream>
#include <unordered_map>
#include <stack>

//
// Created by polarnight on 23-7-8.
//

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::unordered_map<char, char> map = {{')', '('}};
        std::stack<int> sta;
        int len = s.size();
        int res = 0;
        int start = -1;

        for (int i = 0; i < len; i++) {
            if (map.count(s[i])) {
                if (!sta.empty() && map[s[i]] == s[sta.top()]) {
                    sta.pop();
                    if (!sta.empty())
                        res = std::max(res, i - sta.top());
                    else
                        res = std::max(res, i - start);
                } else {
                    start = i;
                    sta.push(i);
                }
            } else {
                sta.push(i);
            }
        }
        return res;
    }
};

int main() {
    std::string s = "()(()";

    Solution sol;
    int res = sol.longestValidParentheses(s);

    std::cout << res;

    return 0;
}