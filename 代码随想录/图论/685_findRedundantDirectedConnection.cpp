#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
// Created by polarnight on 23-11-30, 下午4:13.
//

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

    }
};

int main685() {
    vector<vector<int>> edges = {{1, 2},
                                 {1, 3},
                                 {2, 3}};

    Solution sol;
    vector<int> result = sol.findRedundantDirectedConnection(edges);

    for (auto &res: result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}