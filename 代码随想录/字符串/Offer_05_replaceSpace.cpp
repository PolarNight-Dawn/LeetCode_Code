#include <iostream>

//
// Created by polarnight on 23-9-17, 下午3:06.
//

class Solution {
public:
    // 使用了0(n)的额外空间
    // std::string replaceSpace(std::string s) {
    //     std::string  str;
    //
    //     for (auto &vec : s) {
    //         if (vec == ' ') str += "%20";
    //         else str += vec;
    //     }
    //
    //     return str;
    // }

    // C++字符串可变，可以原地修改，使用0(1)的额外空间
    std::string replaceSpace(std::string s) {
        int count = 0;
        int len = s.size();

        for (auto &vec : s) {
            if (vec == ' ') count++;
        }

        s.resize(len + 2 * count);

        int new_size = s.size() - 1;
        for (int i = len - 1; i >= 0; i--) {
            if (i == new_size) break;
            if (s[i] != ' ') s[new_size--] = s[i];
            else {
                s[new_size--] = '0';
                s[new_size--] = '2';
                s[new_size--] = '%';
            }
        }

        return s;
    }
};

int mainO05() {
    std::string  s = "We are happy.";

    Solution sol;
    std::cout << sol.replaceSpace(s);

    return 0;
}