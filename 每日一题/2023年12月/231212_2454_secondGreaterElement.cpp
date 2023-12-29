#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
//
// Created by polarnight on 23-12-12, 下午2:43.
//

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int len = nums.size();
        stack<int> sta;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
        vector<int> result(len, -1);

        for (int i = 0; i < len; i++) {
            while (!que.empty() && que.top().first < nums[i]) {
                result[que.top().second] = nums[i];
                que.pop();
            }

            while (!sta.empty() && nums[sta.top()] < nums[i]) {
                que.emplace(nums[sta.top()], sta.top());
                sta.pop();
            }
            sta.push(i);
        }
        return result;
    }
};

int main231212() {
    vector<int> nums = {2,4,0,9,6};

    Solution sol;
    auto result = sol.secondGreaterElement(nums);

    for (auto &vec : result) {
        cout << vec << " ";
    }
    cout << endl;

    return 0;
}