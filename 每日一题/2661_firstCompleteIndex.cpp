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
        vector<int> row(mat[0].size()), col(mat.size());
        unordered_map<int, int> hash_row, hash_col;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                hash_row[mat[i][j]] = i;
                hash_col[mat[i][j]] = j;
            }
        }

        int arr_size = arr.size();
        for (int i = 0; i < arr_size; i++) {
            row[hash_row[arr[i]]]++;
            if (row[hash_row[arr[i]]] == mat.size()) {
                int min_num = INT32_MAX;
                for (int j = 0; j < mat[0].size(); j++) {
                    min_num = min(min_num, mat[hash_row[arr[i]]][j]);
                }
            }
            col[hash_col[arr[i]]]++;
            if (col[hash_col[arr[i]]] == mat[0].size()) {
                int min_num = INT32_MAX;
                for (int j = 0; j < mat.size(); j++) {
                    min_num = min(min_num, mat[j][hash_col[arr[i]]]);
                }
            }
        }
        return -1;
    }
};

int main2661() {
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};

    Solution sol;
    cout << sol.firstCompleteIndex(arr, mat);

    return 0;
}
