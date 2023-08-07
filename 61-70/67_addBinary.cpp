#include <iostream>

//
// Created by polarnight on 23-8-7.
//

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res;
        int len = std::max(a.size(), b.size());
        int m = b.size();
        if (len == b.size()) {
            std::string tmp = b;
            b = a;
            a = tmp;
        }

        int sum = 0, carry = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (a.size() != b.size()) {
                if ( len - i > b.size()) sum = (a[i] - '0') + carry;
                else sum = (a[i] - '0') + (b[b.size() - len + i] - '0') + carry;
            } else sum = (a[i] - '0') + (b[i] - '0') + carry;

            carry = 0;
            if (sum >= 2) {
                res.insert(res.begin(), (sum - 2) + '0');
                carry = 1;
            } else res.insert(res.begin(), sum + '0');
        }

        if (carry == 1) res.insert(res.begin(), 1 + '0');
        return res;
    }
};

int main() {
    std::string a = "1";
    std::string b = "1111";

    Solution sol;
    std::cout << sol.addBinary(a, b);

    return 0;
}