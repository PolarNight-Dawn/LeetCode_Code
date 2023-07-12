#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

//
// Created by polarnight on 23-7-12.
//

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        std::vector<std::vector<int>> raw(9, std::vector(9, 0));
        std::vector<std::vector<int>> col(9, std::vector(9, 0));
        std::vector<std::vector<int>> area(9, std::vector(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                int u = c - '1';
                int index = (i / 3) * 3 + j / 3;
                if (raw[i][u] != 0 || col[j][u] != 0 || area[index][u] != 0) return false;
                raw[i][u]++;
                col[j][u]++;
                area[index][u]++;
            }
        }
        return true;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    std::cout << sol.isValidSudoku(board);

    return 0;
}