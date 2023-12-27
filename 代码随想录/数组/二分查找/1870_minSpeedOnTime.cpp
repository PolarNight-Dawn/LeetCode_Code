#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//
// Created by polarnight on 23-12-25, 下午2:52.
//

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        long long hr = llround(hour * 100);
        if (hr <= (n - 1) * 100) return -1;

        function<bool(int)> Check = [&](int a) -> bool {
            long long time = 0;
            for (int i = 0; i < n - 1; i++)
                time += (dist[i] - 1) / a + 1;
            time *= a;
            time += dist[n - 1];
            return time * 100 > hr * a;
        };

        int left = 1, right = 1e7;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid)) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

int main1870() {
    vector<int> dist = {1,3,2};
    double hour = 2.7;

    Solution sol;
    cout << sol.minSpeedOnTime(dist, hour);

    return 0;
}