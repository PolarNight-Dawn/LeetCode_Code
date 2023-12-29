#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-19, 下午2:45.
//

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = mat.size() - 2;

        function<int(vector<int> &)> index_max = [&](vector<int> &a) -> int {
            return max_element(mat.begin(), mat.end()) - mat.begin();
        };

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = index_max(mat[i]);
            if (mat[i][j] > mat[i + 1][j]) right = i - 1;
            else left = i + 1;
        }
        return {left, index_max(mat[left])};
    }
};

int main2312191901() {
    vector<vector<int>> mat = {{7, 2, 3, 1, 2}, {6, 5, 4, 2, 1}};

    Solution sol;
    auto results = sol.findPeakGrid(mat);

    for (auto &result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}