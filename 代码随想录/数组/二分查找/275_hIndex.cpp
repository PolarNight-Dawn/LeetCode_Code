#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-18, 下午9:37.
//

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[n - mid] >= mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

int main275() {
    vector<int> citations = {0,1,3,5,6};

    Solution sol;
    cout << sol.hIndex(citations);

    return 0;
}