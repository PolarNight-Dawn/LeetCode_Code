#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-18, 下午1:48.
//

class Solution {
public:
    // std::string reverseWords(std::string s) {
    //     std::string str;
    //     int left = 0, right = 0;
    //     left = right = s.size() - 1;
    //
    //     if (s.size() == 1 || s.size() == 0) return s;
    //
    //     for (int i = s.size() - 1; i >= 0; i--) {
    //         // 去除原字符串s的尾随空格，相当于新字符串str的前导空格
    //         if (i == s.size() - 1) {
    //             while (s[i] == ' ') {
    //                 i--;
    //                 left = --right;
    //             }
    //             continue;
    //         }
    //
    //         // 扩展滑动窗口向右移动
    //         left--;
    //
    //         // 字符串存在单词间的多个空格的处理
    //         if (s[i] == ' ') {
    //             while (i > 0 && s[i - 1] == ' ') i--;
    //             str += s.substr(left + 1, right - left);
    //             // 去除新字符串str的尾随空格
    //             if (i > 0) str += '_';
    //             // 重新定义滑动窗口的位置
    //             left = i;
    //             right = left - 1;
    //             continue;
    //         }
    //
    //         // 原字符串s存在前导空格的处理
    //         if (i == 0) str += s.substr(left, right - left + 1);
    //     }
    //
    //     return str;
    // }

    //! 简化代码 \快慢双指针
    std::string reverseWords(std::string s) {
        //! \删除首尾空格
        // int front = 0, back = s.size() - 1;
        // while (front < s.size() && s[front] == ' ') front++;
        // while (back >= 0 && s[back] == ' ') back--;
        // s = s.substr(front, back - front + 1);
        // 简化代码
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);

        std::string str;
        int left = s.size() - 1, right = s.size() - 1;
        while (left >= 0) {
            while (left >= 0 && s[left] != ' ') left--;
            str += s.substr(left + 1, right - left) + ' ';
            while (left >= 0 && s[left] == ' ') left--;
            right = left;
        }

        // str.erase(0, s.find_first_not_of(' '));
        str.erase(s.find_last_not_of(' ') + 1);
        return str;
    }
};

int main151() {
    std::string s = "  a  ";

    Solution sol;
    std::cout << sol.reverseWords(s);

    return 0;
}