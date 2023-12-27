#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-25, 下午2:05.
//

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        function<int(int, int)> Check = [&](int a, int b) -> int {
            return a * 2 + (b - a) * 4;
        };

        int left = 0, right = cheeseSlices, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (Check(mid, cheeseSlices) > tomatoSlices) left = mid + 1;
            else if (Check(mid, cheeseSlices) < tomatoSlices) right = mid - 1;
            else {
                ans = mid;
                break;
            }
        }

        return ans != -1 ? vector<int>{cheeseSlices - ans, ans} : vector<int>{};
    }
};

int main231225_1276() {
    int tomatoSlices = 0;
    int cheeseSlices = 0;

    Solution sol;
    auto results = sol.numOfBurgers(tomatoSlices, cheeseSlices);

    for (auto &result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}