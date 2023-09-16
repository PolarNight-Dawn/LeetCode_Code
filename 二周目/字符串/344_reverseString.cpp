#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-16, 下午2:18.
//

class Solution {
public:
    //! \TLE 冒泡排序 时间复杂度为0(n^2^)
    // void reverseString(std::vector<char> &s) {
    //     int len = s.size();
    //     while (len > 0) {
    //         for (int j = 1; j <= len - 1; j++) {
    //             char tmp = s[j - 1];
    //             s[j - 1] = s[j];
    //             s[j] = tmp;
    //         }
    //         len--;
    //     }
    //
    //     return;
    // }

    // 双指针法 时间复杂度为0(n)
    void reverseString(std::vector<char> &s) {
        // int left = 0;
        // int right = s.size() - 1;
        //
        // while (left < right) {
        //     char tmp = s[left];
        //     s[left] = s[right];
        //     s[right] = tmp;
        //     left++;
        //     right--;
        // }

        // 简化代码
        // 另外强调对于库函数的使用 当你知道这个库函数的实现原理，并且库函数使用仅是解题的一部分，就可以
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
            std::swap(s[left], s[right]);
        }

        return;
    }
};

int main() {
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;
    sol.reverseString(s);

    for (auto &vec: s) {
        std::cout << vec << " ";
    }

    return 0;
}