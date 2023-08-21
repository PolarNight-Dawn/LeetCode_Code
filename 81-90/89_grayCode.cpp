#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-20.
//

class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> gray;
        for (int binary = 0; binary < (1 << n); binary++) {
            gray.push_back(binary ^ (binary >> 1));
        }
        return gray;
    }
};

int main89() {
    int n = 2; // Replace

    Solution sol;// with the desired value of n
    std::vector<int> result = sol.grayCode(n);

    // Printing the Gray codes
    for (int num: result) {
        std::cout << num << " ";
    }

    return 0;
}
