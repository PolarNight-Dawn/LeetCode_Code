#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>

using namespace std;

//
// Created by polarnight on 23-12-3, 下午11:09.
//

class Solution {
public:
    int dfs(vector<int>& cardPoints, int start, int end, int k){
        if(k == 0) return 0;
        if(start == end) return cardPoints[start];
        int point1 = cardPoints[start] + dfs(cardPoints, start + 1, end, k - 1);
        int point2 = cardPoints[end] + dfs(cardPoints, start, end - 1, k - 1);
        return max(point1, point2);
    }

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        return dfs(cardPoints, 0, n - 1, k);
    }

    // int maxScore(vector<int> &cardPoints, int k) {
    //     int n = cardPoints.size();
    //     int m = n - k;
    //     int s = accumulate(cardPoints.begin(), cardPoints.begin() + m, 0);
    //     int min_s = s;
    //     for (int i = m; i < n; i++) {
    //         s += cardPoints[i] - cardPoints[i - m];
    //         min_s = min(min_s, s);
    //     }
    //     return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_s;
    // }
};

int main1423() {
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;

    Solution sol;
    cout << sol.maxScore(cardPoints, k);

    return 0;
}