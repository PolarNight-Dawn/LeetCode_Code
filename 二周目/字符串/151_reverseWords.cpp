#include <iostream>

//
// Created by polarnight on 23-9-18, 下午1:48.
//

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string str;
        int left = 0, right = 0;
        left = right = s.size() - 1;

        if (s.size() == 1 || s.size() == 0) return s;

        for (int i = s.size() - 1; i >= 0; i--) {
            // 去除原字符串s的尾随空格，相当于新字符串str的前导空格
            if (i == s.size() - 1) {
                while (s[i] == ' ') {
                    i--;
                    left = --right;
                }
                continue;
            }

            // 扩展滑动窗口向右移动
            left--;

            // 字符串存在单词间的多个空格的处理
            if (s[i] == ' ') {
                while (i > 0 && s[i - 1] == ' ') i--;
                str += s.substr(left + 1, right - left);
                // 去除新字符串str的尾随空格
                if (i > 0) str += '_';
                // 重新定义滑动窗口的位置
                left = i;
                right = left - 1;
                continue;
            }

            // 原字符串s存在前导空格的处理
            if (i == 0) str += s.substr(left, right - left + 1);
        }

        return str;
    }
};

int main() {
    std::string s = "a";

    Solution sol;
    std::cout << sol.reverseWords(s);

    return 0;
}