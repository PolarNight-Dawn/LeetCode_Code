#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
//
// Created by polarnight on 23-12-23, 下午7:32.
//

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> que;

        for (auto  &pile : piles)
            que.push(pile);

        while (k--) {
            int tmp = que.top();
            que.pop();
            if (tmp & 1) tmp++;
            tmp >>= 1;
            que.push(tmp);
        }

        int ans = 0;
        while (!que.empty()) {
            ans += que.top();
            que.pop();
        }
        return ans;
    }
};

int main2312221962() {
    vector<int> piles = {5,4,9};
    int k = 2;

    Solution sol;
    cout << sol.minStoneSum(piles, k);

    return 0;
}

