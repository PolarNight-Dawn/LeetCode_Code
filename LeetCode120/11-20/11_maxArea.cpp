#include <iostream>
#include <vector>

using namespace std;
//
// Created by polarnight on 23-4-18.
//

class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();

        int size = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            int temp = h * (j - i);
            size = max(temp, size);
            if (height[i] == h) i++;
            if (height[j] == h) j--;
        }
        //! \减少了一些重复代码
        //! \增加了一些变量以提高复用性
        return size;
    }
};

int main11() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution sol;
    cout << sol.maxArea(height);

    return 0;
}