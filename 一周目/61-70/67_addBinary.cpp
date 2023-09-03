#include <iostream>
#include <algorithm>

//
// Created by polarnight on 23-8-7.
//

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res;
        res.reserve(a.size() + b.size());

        int val = 0, cnt01 = a.size() - 1, cnt02 = b.size() - 1;
        while (cnt01 >= 0 || cnt02 >= 0 || val == 1) {
            val += cnt01 >= 0 ? a[cnt01--] - '0' : 0;
            val += cnt02 >= 0 ? b[cnt02--] - '0' : 0;
            res.push_back((val & 1) + '0');
            val >>= 1;
        }

        std::reverse(res.begin(), res.end());
        return  res;
    }
};

int main67() {
    std::string a = "1";
    std::string b = "1111";

    Solution sol;
    std::cout << sol.addBinary(a, b);

    return 0;
}