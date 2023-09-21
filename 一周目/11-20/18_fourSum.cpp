#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-5-9.
//

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        size_t len = nums.size();

        if (len < 4) return res;

        for (int i = 0; i < len - 3; i++) {
            //! \适当的剪枝可以加快运行速度
            if (target <= 0 && nums[i] > 0) break;
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

            if ((long)nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < len - 2; j++) {
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;

                if ((long)nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) continue;

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    long fourSum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (fourSum > target) right--;
                    else if (fourSum < target) left++;
                    else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[right] == nums[right - 1]) right--;
                        while (left < right && nums[left] == nums[left + 1]) left++;

                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};

int main18() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution sol;
    vector<vector<int>> vec = sol.fourSum(nums, target);

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            int x = vec[i][j];
            // 对x进行操作，比如输出
            cout << x << " ";
        }
        cout << endl; // 遍历完一行后输出换行符
    }

    return 0;
}