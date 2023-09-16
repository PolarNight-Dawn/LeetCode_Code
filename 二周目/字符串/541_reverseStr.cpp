#include <iostream>

//
// Created by polarnight on 23-9-16, 下午3:17.
//

class Solution {
public:
    std::string ReverseStr(std::string str) {
        int len = str.size();
        for (int left = 0, right = len - 1; left < right; left++, right--) {
            std::swap(str[left], str[right]);
        }
        return str;
    }

    std::string reverseStr(std::string s, int k) {
        std::string str;
        while(true) {
            int len = s.size();
            if (len < k) {
                str += ReverseStr(s);
                break;
            }
            if (len < 2 * k && len >= k) {
                str += ReverseStr(s.substr(0, k));
                str += s.substr(k);
                break;
            }

            str += ReverseStr(s.substr(0, k));
            str += s.substr(k, k);
            s = s.substr(2 * k);
        }

        return str;
    }
};

int main() {
    std::string s = "abcdefg";
    int k = 1;

    Solution sol;
    std::cout << sol.reverseStr(s, k);

    return 0;
}