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
            if (height[i] <= height[j]) {
                size = max((j - i) * height[i], size);
                i++;
            } else {
                size = max((j - i) * height[j], size);
                j--;
            }
        }
        return size;
    }
};

int main11 () {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution sol;
    cout << sol.maxArea(height);

    return 0;
}