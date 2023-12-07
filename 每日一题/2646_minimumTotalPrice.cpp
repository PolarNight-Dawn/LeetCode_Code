#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 23-12-6, 下午5:35.
//

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

    }
};

int main2646() {
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
    vector<int> price = {2,2,10,6};
    vector<vector<int>> trips = {{0, 3}, {2, 1}, {2, 3}};

    Solution sol;
    cout << sol.minimumTotalPrice(n, edges, price, trips);

    return 0;
}

