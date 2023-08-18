#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-18.
//

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> heights(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] += matrix[i][j] - '0';
            }
        }

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
    std::vector<std::vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                             {'1', '0', '1', '1', '1'},
                                             {'1', '1', '1', '1', '1'},
                                             {'1', '0', '0', '1', '0'}};

    Solution sol;
    std::cout << sol.maximalRectangle(matrix);

    return 0;
}