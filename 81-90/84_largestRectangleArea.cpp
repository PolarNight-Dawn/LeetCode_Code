#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-17.
//

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int len = heights.size();
        std::vector<int> leftFirstmin(len, -1);
        std::vector<int> rightFirstmin(len, len);

        for (int i = 1; i < len; i++) {
            int index = i - 1;
            while (index >= 0 && heights[index] >= heights[i]) index = leftFirstmin[index];
            leftFirstmin[i] = index;
        }

        for (int j = len - 2; j >= 0; j--) {
            int index = j + 1;
            while (index < len && heights[index] >= heights[j]) index = rightFirstmin[index];
            rightFirstmin[j] = index;
        }

        int maxSize = 0;
        for (int z = 0; z < len; z++) {
            int size =  (rightFirstmin[z] - leftFirstmin[z] - 1) * heights[z];
            maxSize = std::max(size, maxSize);
        }

        return maxSize;
    }
};

int main() {
    std::vector<int> heights = {2,1,5,6,2,3};

    Solution sol;
    std::cout << sol.largestRectangleArea(heights);

    return 0;
}