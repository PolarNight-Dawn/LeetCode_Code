#include <iostream>
#include <vector>
#include <unordered_map>

//
// Created by polarnight on 23-9-6.
//

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::unordered_map<int, int> tmp;

        int len = INT32_MIN;
        int left = 0, right = 0;
        while (right < fruits.size()) {
            tmp[fruits[right]]++;
            while (tmp.size() > 2) {
                auto it = tmp.find(fruits[left]);
                it->second--;
                if (it->second == 0) {
                    tmp.erase(it);
                }
                left++;
            }
            len = std::max(right - left + 1, len);
            right++;
        }

        return len == INT32_MIN ? 0 : len;
    }
};

int main904() {
    std::vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};

    Solution sol;
    std::cout << sol.totalFruit(fruits);

    return 0;
}