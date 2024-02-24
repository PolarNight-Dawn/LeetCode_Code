#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
//
// Created by polarnight on 24-1-25, 下午4:03.
//

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = position.back() - position[0];

        function<bool(int)> Check = [&](int mid) -> bool {
            int count = 1, pre = position[0];
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - pre >= mid) pre = position[i], count++;
            }
            return count < m;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};

int main1552() {
    vector<int> position = {1,2,3,4,7};
    int m = 3;

    Solution sol;
    cout << sol.maxDistance(position, m);

    return 0;
}