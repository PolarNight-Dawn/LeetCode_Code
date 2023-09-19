#include <iostream>

//
// Created by polarnight on 23-6-25.
//

class Solution {
public:
    // int strStr(std::string haystack, std::string needle) {
    //     int n = 0, res = 0;
    //     int lenHay = haystack.size();
    //     int lenNee = needle.size();
    //
    //     while (n < lenHay) {
    //         if (haystack[n] == needle[0]) {
    //             res = n;
    //             int left = n + 1;
    //             int right = 1;
    //             if (right == lenNee) return res;
    //             while (haystack[left] == needle[right] && left < lenHay) {
    //                 left++;
    //                 right++;
    //                 if (right == lenNee) {
    //                     return res;
    //                 }
    //             }
    //             n = res + 1;
    //             // n++;
    //         } else {
    //             n++;
    //         }
    //     }
    //
    //     return -1;
    // }

    // 二周目重刷 双指针法
    int strStr(std::string haystack, std::string needle) {
        int cnt = 0, len = 0;

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[len]) len++;
            else {
                i = cnt++;
                len = 0;
            }
            if (len == needle.size()) return cnt;
        }

        return -1;
    }
};

int main28() {
    std::string haystack = "mississippi";
    std::string needle = "issip";

    Solution sol;
    std::cout << sol.strStr(haystack, needle);

    return 0;
}