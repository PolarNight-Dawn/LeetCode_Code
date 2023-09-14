#include <iostream>
#include <unordered_set>

//
// Created by polarnight on 23-9-14, 下午2:12.
//

class Solution {
public:
    int get_sum(int n ) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> set;
        while (true) {
            int sum = get_sum(n);
            if (sum == 1) return true;
            else {
                if (set.find(sum) != set.end()) return false;
                else set.insert(sum);
            }
            n = sum;
        }
    }
};

int main() {
    int n = 19;

    Solution sol;
    std::cout << sol.isHappy(n);

    return 0;
}