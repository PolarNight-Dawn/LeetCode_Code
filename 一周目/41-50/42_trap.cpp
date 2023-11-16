#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

//
// Created by polarnight on 23-7-18.
//

class Solution {
public:
    // int trap(std::vector<int>& height) {
    //     int len = height.size();
    //     int size = 0;
    //     for (int i = 0; i < len; i++) {
    //         if (i == 0 || i == height.size() - 1) continue;
    //
    //         int rHeight = height[i];
    //         int lHeight = height[i];
    //         for (int r = i + 1; r < len; r++) {
    //             if (height[r] > rHeight) rHeight = height[r];
    //         }
    //         for (int l = i - 1; l >= 0; l--) {
    //             if (height[l] > lHeight) lHeight = height[l];
    //         }
    //         int h = std::min(lHeight, rHeight) - height[i];
    //         if (h > 0) size += h;
    //     }
    //     return size;
    // }

    //! \二周目 单调栈
    int trap(std::vector<int>& height) {
        int height_len = height.size();
        if (height_len == 1) return 0;
        std::stack<int> sta;

        int rain_water_area = 0;
        for (int i = 0; i < height_len; i++) {
           while (!sta.empty() && height[i] > height[sta.top()]) {
               int mid = sta.top();
               sta.pop();
               if (!sta.empty()) {
                   int heights = std::min(height[sta.top()], height[i]) - height[mid];
                   rain_water_area += heights * (i - sta.top() - 1);
               }
           }
           sta.push(i);
        }
        return rain_water_area;
    }
};

int main42() {
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution sol;
    std::cout << sol.trap(height);

    return 0;
}