#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
//
// Created by polarnight on 23-5-9.
//

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int cnt = 0;
        unordered_set<string> visited;

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    long int twoSum = nums[i] + nums[j];
                    long int fourSum = twoSum + nums[left] + nums[right];
                    if (fourSum < target) {
                        left++;
                    } else if (fourSum > target) {
                        right--;
                    } else {
                        string key = to_string(nums[i]) + "," + to_string(nums[j]) + "," + to_string(nums[left]) + "," +
                                     to_string(nums[right]);
                        if (visited.find(key) == visited.end()) {
                            res.push_back({nums[i], nums[j], nums[left], nums[right]});
                            visited.insert(key);
                        }
                        left++;
                        right--;
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