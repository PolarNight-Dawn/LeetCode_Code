#include <iostream>
#include <algorithm>

//
// Created by polarnight on 23-9-19, 下午1:35.
//

class Solution {
public:
    // 申请了0(n)的额外空间，调用了函数，时间复杂度为0(n)
    // std::string reverseLeftWords(std::string s, int n) {
    //     std::string str1 = s.substr(0, n);
    //     std::string str2 = s.substr(n);
    //
    //     return str2 + str1;
    // }

    // 不申请额外空间
    std::string reverseLeftWords(std::string s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + s.size() - n);
        reverse(s.begin() + s.size() - n, s.end());

        return s;
    }
};

int main() {
    std::string s = "abcdefg";
    int n = 2;

    Solution sol;
    std::cout << sol.reverseLeftWords(s, n);

    return 0;
}