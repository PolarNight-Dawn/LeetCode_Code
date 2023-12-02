#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//
// Created by polarnight on 23-12-2, 下午11:36.
//

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int trip[1001] = {};

        for (int i = 0; i < trips.size(); i++) {
            for (int j = trips[i][1]; j < trips[i][2]; j++) {
                trip[j] += trips[i][0];
            }
        }

        for (int i = 0; i < 1000; i++) {
            if (trip[i] > capacity) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> trips = {{2, 1, 5}, {3, 5, 7}};
    int capacity = 3;

    Solution sol;
    cout << sol.carPooling(trips, capacity);

    return 0;
}