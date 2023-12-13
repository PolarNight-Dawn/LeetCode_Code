#include <iostream>

//
// Created by polarnight on 23-9-16, 下午3:17.
//

class Solution {
public:
    void ReverseStr(std::string &str, int start, int end) {
        for (int left = start, right = end; left < right; left++, right--) {
            std::swap(str[left], str[right]);
        }
    }

    // std::string reverseStr(std::string s, int k) {
    //     std::string str;
    //     while(true) {
    //         int len = s.size();
    //         if (len < k) {
    //             str += ReverseStr(s);
    //             break;
    //         }
    //         if (len < 2 * k && len >= k) {
    //             str += ReverseStr(s.substr(0, k));
    //             str += s.substr(k);
    //             break;
    //         }
    //
    //         str += ReverseStr(s.substr(0, k));
    //         str += s.substr(k, k);
    //         s = s.substr(2 * k);
    //     }
    //
    //     return str;
    // }

    // 优化代码 当需要一段一段去处理字符串的时候，可以想想在for循环的表达上做做文章
    std::string reverseStr(std::string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                ReverseStr(s, i, i + k - 1);
                continue;
            }
            ReverseStr(s, i, s.size() - 1);
        }
        return s;
    }
};

int main541() {
    std::string s = "abcdefg";
    int k = 1;

    Solution sol;
    std::cout << sol.reverseStr(s, k);

    return 0;
}