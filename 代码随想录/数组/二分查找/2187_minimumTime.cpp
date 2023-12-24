#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-20, 下午5:26.
//

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long max_time = *max_element(time.begin(), time.end());
        long long left = 1, right = max_time * totalTrips - 1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long trips = 0;
            for (auto &t : time)
                trips += mid / t;
            if (trips >= totalTrips) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main2187() {
    vector<int> time = {1,2,3};
    int totalTrips = 5;

    Solution sol;
    cout << sol.minimumTime(time, totalTrips);

    return 0;
}