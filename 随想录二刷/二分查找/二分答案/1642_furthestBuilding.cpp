#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//
// Created by polarnight on 23-12-30, 下午4:47.
//

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int left = 0, right = heights.size() - 1;

        function<bool(int)> Check = [&](int mid) -> bool {
            priority_queue<int> que;
            for (int i = 0; i < mid; i++)
                if (heights[i + 1] > heights[i]) que.push(heights[i + 1] - heights[i]);
            if (que.size() <= ladders) return true;
            int _bricks = bricks, _ladders = ladders;
            while (_ladders--) que.pop();
            while (!que.empty() && _bricks >= que.top()) {
                _bricks -= que.top();
                que.pop();
            }
            return que.empty();
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

int main1642() {
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5, ladders = 1;

    Solution sol;
    cout << sol.furthestBuilding(heights, bricks, ladders);

    return 0;
}