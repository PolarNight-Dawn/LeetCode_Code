#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-7-18.
//

class Solution {
public:
    int trap(std::vector<int>& height) {
        int len = height.size();
        int size = 0;
        for (int i = 0; i < len; i++) {
            if (i == 0 || i == height.size() - 1) continue;

            int rHeight = height[i];
            int lHeight = height[i];
            for (int r = i + 1; r < len; r++) {
                if (height[r] > rHeight) rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) lHeight = height[l];
            }
            int h = std::min(lHeight, rHeight) - height[i];
            if (h > 0) size += h;
        }
        return size;
    }
};

int main42() {
    std::vector<int> height = {4, 2, 3};

    Solution sol;
    std::cout << sol.trap(height);

    return 0;
}