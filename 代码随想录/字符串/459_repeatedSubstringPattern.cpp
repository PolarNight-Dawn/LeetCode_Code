#include <iostream>
#include <unordered_map>
#include <unordered_set>

//
// Created by polarnight on 23-9-19, 下午3:25.
//

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

int main459() {
    std::string  s = "aaa";

    Solution sol;
    std::cout << sol.repeatedSubstringPattern(s);

    return 0;
}