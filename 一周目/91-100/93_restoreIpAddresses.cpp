#include <iostream>
#include <vector>
#include <cmath>

//
// Created by polarnight on 23-8-22.
//

class Solution {
public:
    int str_to_int(std::string s, int length, int start) {
        int ans = 0;
        for (int i = 0; i < length; i++) {
            int order = pow(10, length - i - 1);
            ans += (s[start + i] - '0') * order;
        }
        return ans;
    }

    void backTracing(std::vector<std::string> &res, std::string s,std::string str,
                     int start, int depth) {
        if (depth == 0 && str.size() != s.size() + 3) return;
        if (depth == 0 && str.size() == s.size() + 3) {
            res.push_back(str);
            return;
        }

        for (int i = 1; i <= 3; i++) {
            // IP地址长度错误的处理
            if (str.size() + i > s.size() + 3) continue;

            // IP地址格式错误的处理
            int val = str_to_int(s, i, start);
            if (val < 0 || val > 255) continue;

            // 存在前导零的处理
            if (start >= s.size()) continue;
            std::string tmp = s.substr(start, i);
            if (tmp.size() != 1 && tmp[0] == '0') continue;

            // IP地址的组装
            if (depth == 1) str += tmp;
            else str += tmp + '.';
            backTracing(res, s, str, i + start, depth - 1);
            if (depth == 1) str = str.substr(0, str.size() - i);
            else str = str.substr(0, str.size() - i - 1);
        }
    }

    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::string str;
        std::vector<std::string> res;

        backTracing(res, s, str, 0, 4);

        return res;
    }
};

int main93() {
    std::string s = "1111";

    Solution sol;
    std::vector<std::string > res = sol.restoreIpAddresses(s);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}
