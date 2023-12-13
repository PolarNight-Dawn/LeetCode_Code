#include <iostream>

//
// Created by polarnight on 23-8-6.
//

class Solution {
public:
    bool isValid(const char *cs, int start, int end, bool typeNum) {
        if (start > end) return false;
        if (cs[start] == '+' || cs[start] == '-') start++;

        bool hasDot = false, hasNum = false;
        for (int i = start; i <= end; i++) {
            if (cs[i] == '.') {
                if (typeNum || hasDot) return false;
                hasDot = true;
            } else if (cs[i] >= '0' && cs[i] <= '9') {
                hasNum = true;
            } else return false;
        }

        return hasNum;
    }

    bool isNumber(std::string s) {
        int len = s.size();
        const char *cs = s.c_str();
        int idx = -1;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (idx == -1) idx = i;
                else return false;
            }
        }

        bool res = true;
        if (idx != -1) {
            res &= isValid(cs, 0, idx - 1, false);
            res &= isValid(cs, idx + 1, len - 1, true);
        } else res &= isValid(cs, 0, len - 1, false);

        return res;
    }
};

int main65() {
    std::string s = "-1.";

    Solution sol;
    std::cout << sol.isNumber(s);

    return 0;
}