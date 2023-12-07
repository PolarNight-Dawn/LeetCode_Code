#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//
// Created by polarnight on 23-12-1, 下午9:51.
//

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int raw_nums = mat.size();
        int col_nums = mat[0].size();

        vector<int> raw(raw_nums, col_nums);
        vector<int> col(col_nums, raw_nums);
        vector<pair<int, int>> position(raw_nums * col_nums);

        for (int i = 0; i < raw_nums; i++) {
            for (int j = 0; j < col_nums; j++) {
                position[mat[i][j] - 1].first = i;
                position[mat[i][j] - 1].second = j;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            raw[position[arr[i] - 1].first]--;
            if (raw[position[arr[i] - 1].first] == 0) return i;
            col[position[arr[i] - 1].second]--;
            if (col[position[arr[i] - 1].second] == 0) return i;
        }
        return 0;
    }
};

int main() {
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};

    Solution sol;
    cout << sol.firstCompleteIndex(arr, mat);

    return 0;
}
