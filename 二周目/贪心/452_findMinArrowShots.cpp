#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-10-20, 下午9:15.
//

class Solution {
public:
    // int findMinArrowShots(std::vector<std::vector<int>>& points) {
    //     if (points.empty()) return 0;
    //     std::sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
    //         return a[1] < b[1];
    //     });
    //
    //     int pos = points[0][1];
    //     int cnt = 1;
    //     for (auto &vec : points) {
    //         if (vec[0] > pos) {
    //             pos = vec[1];
    //             ++cnt;
    //         }
    //     }
    //     return cnt;
    // }

    //
        static bool Compare452(const std::vector<int> &a, const std::vector<int> &b) {
            return a[1] < b[1];
        }

    int findMinArrowShots(std::vector<std::vector<int>> &points) {
        if (points.size() == 1) return 1;
        std::sort(points.begin(), points.end(), Compare452);

        int cnt = 0;
        for (int i = 1; i < points.size(); i++) {
            if (i % 2 == 0) {
                if (i == points.size() - 1) cnt++;
                else continue;
            } else {
                if (points[i - 1][1] >= points[i][0]) cnt++;
                else cnt += 2;
            }
        }
        return cnt;
    }
};

int main452() {
    std::vector<std::vector<int>> points = {{10, 16},
                                            {2,  8},
                                            {1,  6},
                                            {7,  12}};

    Solution sol;
    std::cout << sol.findMinArrowShots(points);

    return 0;
}