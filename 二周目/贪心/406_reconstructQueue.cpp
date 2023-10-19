#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-19, 下午5:12.
//

class Solution {
public:
    static bool Compare(const std::vector<int> &a, const std::vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people) {
        std::sort(people.begin(), people.end(), Compare);

        std::vector<std::vector<int>> res;
        for (int i = 0; i < people.size(); i++) {
            int pos = people[i][1];
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

    Solution sol;
    std::vector<std::vector<int>> res = sol.reconstructQueue(people);

    for (auto &tmp : res) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}