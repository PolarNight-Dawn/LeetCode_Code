#include <iostream>

//
// Created by polarnight on 23-9-20, 下午5:22.
//

class Solution {
public:
    // 快慢双指针 代码太丑陋了
    int maxPower(std::string s) {
        int s_len = s.size();
        int len = 0;
        for (int slow = 0, fast = 0; fast < s.size(); fast++) {
            if (s[fast] != s[slow]) {
                len = std::max(fast - slow, len);
                slow = fast;
            }
            if (len == 0 && fast == s.size() - 1) len = s.size();
            if (len != 0 && fast == s.size() - 1) len = std::max(fast - slow + 1, len);
        }

        return len;
    }
};

int main() {
    std::string s = "aabbbbbccccdddddddeffffffggghhhhhiiiiijjjkkkkkllllmmmmmnnnnnoopppqrrrrsssttttuuuuvvvvwwwwwwwxxxxxyyyzzzzzzzz";

    Solution sol;
    std::cout << sol.maxPower(s);

    return 0;
}