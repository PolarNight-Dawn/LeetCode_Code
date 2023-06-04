#include <iostream>

using namespace std;
//
// Created by polarnight on 23-4-15.
//
class Solution {
public:
    int myAtoi(string s) {
        size_t i = 0;
        size_t len = s.length();
        while (i < len && isspace((s.at(i)))) {
            ++i;
        }

        bool flag = false;
        if (s[i] == '-') {
            ++i;
            flag = true;
        } else if (s[i] == '+') {
            ++i;
        }

        s = s.substr(i) ;
        int64_t result = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                result = result * 10 + (c - '0');
                if (result > 2147483648) {
                    result = 2147483648;
                    break;
                }
            } else {
                break;
            }
        }

        if (flag) {
            return int(0 - result);
        }
        if (result == 2147483648) {
            result = 2147483647;
        }
        return int(result);
    }
};

int main08 () {
    string s = "  -42 with code";

    Solution sol;
    cout << sol.myAtoi(s);

    return 0;
}
