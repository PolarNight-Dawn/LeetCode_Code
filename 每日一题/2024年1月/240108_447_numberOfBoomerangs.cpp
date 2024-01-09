#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//
// Created by polarnight on 24-1-8, 下午2:35.
//

class Solution {
public:
    //! \TLE
    //! 时间复杂度O(n^3)
    // int numberOfBoomerangs(vector<vector<int>>& points) {
    //     function<bool(vector<int>, vector<int>, vector<int>)> Check = [&](vector<int> i, vector<int> j, vector<int> k) -> bool {
    //         double dis_ij = sqrt(pow(abs(j[0] - i[0]), 2) + pow(abs(j[1] - i[1]), 2));
    //         double dis_ik = sqrt(pow(abs(k[0] - i[0]), 2) + pow(abs(k[1] - i[1]), 2));
    //         return dis_ik == dis_ij;
    //     };
    //
    //     int ans = 0;
    //     for (int i = 0; i < points.size(); i++) {
    //         for (int j = 0; j < points.size(); j++) {
    //             if (j == i) continue;
    //             for (int z = 0; z < points.size(); z++) {
    //                 if (z == i || z == j) continue;
    //                 if (Check(points[i], points[j], points[z])) ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }


    int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto &p1: points) {
            cnt.clear();
            for (auto &p2: points) {
                int d2 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                ans += cnt[d2]++ * 2;
            }
        }
        return ans;
    }
};

int main240108447() {
    vector<vector<int>> points = {{0, 0},
                                  {1, 0},
                                  {2, 0}};

    Solution sol;
    cout << sol.numberOfBoomerangs(points);

    return 0;
}