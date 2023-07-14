#include <iostream>

//
// Created by polarnight on 23-7-14.
//

class Solution {
public:
    std::string recurs(std::string &res, std::string &str, int newI, int cnt) {
        if (str.size() == 1) {
            res += "1";
            res += str[0];
            return res;
        }
        for (int i = newI; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {
                cnt ++;
                if (i + 1 == str.size()) {
                    res += static_cast<char>(cnt + '0');
                    res += str[i];
                    break;
                }
                continue;
            } else {
                res += static_cast<char>(cnt + '0');
                res += str[i - 1];
                if (i + 1 == str.size()) {
                    res += "1";
                    res += str[i];
                    break;
                }
                return recurs(res, str, i + 1, 1);
            }
        }
        return res;
    }

    std::string countAndSay(int n) {
        std::string str = "1";

        if (n == 1)  return str;

        n = n - 1;
        while(n) {
            std::string res;
            str = recurs(res, str, 1, 1);
            n--;
        }

        return str;
    }
};

int main() {
    int n = 5;

    Solution sol;
    std::string str = sol.countAndSay(n);

    std::cout << str;

    return 0;
}