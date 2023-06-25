#include <iostream>

//
// Created by polarnight on 23-6-25.
//

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = 0, res = 0;
        int lenHay = haystack.size();
        int lenNee = needle.size();

        while (n < lenHay) {
            if (haystack[n] == needle[0]) {
                res = n;
                int left = n + 1;
                int right = 1;
                if (right == lenNee) return res;
                while (haystack[left] == needle[right] && left < lenHay) {
                    left++;
                    right++;
                    if (right == lenNee) {
                        return res;
                    }
                }
                n = res + 1;
            } else {
                n++;
            }
        }

        return -1;
    }
};

int main() {
    std::string haystack = "mississippi";
    std::string needle = "issip";

    Solution sol;
    std::cout << sol.strStr(haystack, needle);

    return 0;
}