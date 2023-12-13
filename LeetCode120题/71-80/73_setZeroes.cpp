#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-11.
//

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> vec;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    std::vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    vec.push_back(tmp);
                }
            }
        }

        for (auto &ans : vec) {
            for (int i = 0; i < m; i++) matrix[i][ans[1]] = 0;
            for (int j = 0; j < n; j++) matrix[ans[0]][j] = 0;
        }
    }
};

int main73() {
    std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    Solution sol;
    sol.setZeroes(matrix);

    for (auto &tmp : matrix) {
        for (auto &vec : tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return  0;
}