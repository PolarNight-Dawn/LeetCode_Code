#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-24.
//

class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int cnt = 0;
        int n = matrix.size();
        if (n % 2 == 0) cnt = n / 2;
        else cnt = (n + 1) / 2;

        for (int i = 0; i < cnt; i++) {
            /*if (i == 1) {
                std::cout << "test";
            }*/
            for (int j = i; j < n - 1 - i; j++) {
                int m = 4, temp = 1001, curI = i, curJ = j, nextI = j, nextJ = n - 1 - i;
                while (m > 0) {
                    if (temp != 1001) {
                        int prev = temp;
                        temp = matrix[nextI][nextJ];
                        matrix[nextI][nextJ] = prev;
                    } else {
                        temp = matrix[nextI][nextJ];
                        matrix[nextI][nextJ] = matrix[curI][curJ];
                    }
                    curI = nextI;
                    curJ = nextJ;
                    nextI = curJ;
                    nextJ = n - 1 - curI;
                    m--;
                }
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{5,  1,  9,  11},
                                            {2,  4,  8,  10},
                                            {13, 3,  6,  7},
                                            {15, 14, 12, 16}};

    Solution sol;
    sol.rotate(matrix);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}