#include <iostream>

//
// Created by polarnight on 23-9-5.
//

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        int sSkipNum = 0; // 记录S的#数量
        int tSkipNum = 0; // 记录T的#数量
        int i = s.size() - 1;
        int j = t.size() - 1;
        while (1) {
            while (i >= 0) { // 从后向前，消除S的#
                if (s[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) { // 从后向前，消除T的#
                if (t[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
            // 后半部分#消除完了，接下来比较S[i] != T[j]
            if (i < 0 || j < 0) break; // S 或者T 遍历到头了
            if (s[i] != t[j]) return false;
            i--;j--;
        }
        // 说明S和T同时遍历完毕
        if (i == -1 && j == -1) return true;
        return false;
    }
};

int main() {
    std::string s = "ab##";
    std::string t = "c#d#";

    Solution sol;
    std::cout << sol.backspaceCompare(s, t);

    return 0;
}