#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-10, 下午8:32.
//

class Solution {
public:
    bool IsPalindromic(std::string &str) {
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }

    void backTracing03(std::vector<std::vector<std::string >> &res, std::vector<std::string> &tmp,
                      std::string &s, int index) {
        if (s.size() == index) {
            res.push_back(tmp);
            return;
        }

        for (int i = 1; i < s.size() - index + 1; i++) {
            std::string str = s.substr(index, i);
            if (!IsPalindromic(str)) continue;
            tmp.push_back(str);
            backTracing03(res, tmp, s, index + i);
            tmp.pop_back();
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string >> res;
        std::vector<std::string> tmp;

        backTracing03(res, tmp, s, 0);

        return res;
    }
};

int main131() {
    std::string  s= "aab";

    Solution sol;
    std::vector<std::vector<std::string >> res = sol.partition(s);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}