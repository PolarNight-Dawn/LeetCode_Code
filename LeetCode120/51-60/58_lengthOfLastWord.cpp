#include <iostream>

//
// Created by polarnight on 23-8-2.
//

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int cnt = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (i > 0 && s[i - 1] != ' ') res = cnt;
                cnt = 0;
                continue;
            }
            cnt++;
            if (i == s.size() - 1) res = cnt;
        }
        return res;
    }
};

int main58() {
    std::string s = "luffy is still joyboy";

    Solution sol;
    std::cout << sol.lengthOfLastWord(s);

    return 0;
}