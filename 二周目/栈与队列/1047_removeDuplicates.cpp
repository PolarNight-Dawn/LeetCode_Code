#include <iostream>
#include <stack>
#include <algorithm>

//
// Created by polarnight on 23-9-23, 下午5:11.
//

class Solution {
public:
    // 栈 时间复杂度O(3n) 空间复杂度O(n)
    // std::string removeDuplicates(std::string s) {
    //     std::stack<char> sta;
    //
    //     for (auto &vec : s) {
    //         if (sta.empty() || sta.top() != vec) sta.push(vec);
    //         else sta.pop();
    //     }
    //
    //     std::string str;
    //     while (!sta.empty()) {
    //         str += sta.top();
    //         sta.pop();
    //     }
    //
    //     reverse(str.begin(), str.end());
    //     return str;
    // }

    // 这里可以用 string 实现栈的功能 时间复杂度O(n) 空间复杂度O(n)
    // 栈的实现会涉及时间复杂度的常数项
    std::string removeDuplicates(std::string s) {
        std::string str;

        for (auto &vec: s) {
            if (str.empty() || str.back() != vec) str.push_back(vec);
            else str.pop_back();
        }

        return str;
    }
};

int main() {
    std::string s = "abbaca";

    Solution sol;
    std::cout << sol.removeDuplicates(s);

    return 0;
}