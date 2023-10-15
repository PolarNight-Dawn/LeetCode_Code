#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-15, 下午5:11.
//

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int count = 0, index = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = index; j < s.size(); j++) {
                if (g[i] <= s[j]) {
                    index = j + 1;
                    count++;
                    break;
                }
                if (g[i] > s[j] && j == s.size() - 1) return count;
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> g = {1, 3};
    std::vector<int> s = {3, 2, 1};

    Solution sol;
    std::cout << sol.findContentChildren(g, s);

    return 0;
}