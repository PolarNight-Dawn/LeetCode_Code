#include <iostream>

//
// Created by polarnight on 23-8-24.
//

class Solution {
public:
    bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3, int i, int j, int k) {
        if (i + j == s3.length()) {
            return true;
        }

        bool isValid = false;

        if (i < s1.length() && s1[i] == s3[k]) {
            isValid = isInterleave(s1, s2, s3, i + 1, j, k + 1);
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            isValid = isValid || isInterleave(s1, s2, s3, i, j + 1, k + 1);
        }

        return isValid;
    }

    bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
};

int main() {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbbaccc";

    Solution sol;
    std::cout << sol.isInterleave(s1, s2, s3);

    return 0;
}