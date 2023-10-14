#include <iostream>
#include <vector>

//
// Created by polarnight on 23-7-13.
//

// class Solution {
// public:
//     bool BackTracing37(std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &raw,
//                      std::vector<std::vector<bool>> &col, std::vector<std::vector<bool>> &area,
//                      int newRaw, int newCol) {
//         if (newCol == 9) return BackTracing37(board, raw, col, area, newRaw + 1, 0);
//         if (newRaw == 9) return true;
//         if (board[newRaw][newCol] != '.') return BackTracing37(board, raw, col, area, newRaw, newCol + 1);
//
//         for (int i = 0; i < 9; ++i) {
//             int index = (newRaw / 3) * 3 + newCol / 3;
//             if ( !raw[newRaw][i] && !col[newCol][i] && !area[index][i]) {
//                 board[newRaw][newCol] = static_cast<char>(i + '1');
//                 raw[newRaw][i] = col[newCol][i] = area[index][i] = true;
//                 if (BackTracing37(board, raw, col, area, newRaw, newCol + 1)) {
//                     break;
//                 } else {
//                     board[newRaw][newCol] = '.';
//                     raw[newRaw][i] = col[newCol][i] = area[index][i] = false;
//                 }
//             }
//         }
//         return board[newRaw][newCol] != '.';
//     }
//
//     void solveSudoku(std::vector<std::vector<char>> &board) {
//         std::vector<std::vector<bool>> raw(9, std::vector(9, false));
//         std::vector<std::vector<bool>> col(9, std::vector(9, false));
//         std::vector<std::vector<bool>> area(9, std::vector(9, false));
//
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] != '.') {
//                     int u = board[i][j] - '1';
//                     int index = (i / 3) * 3 + j / 3;
//                     raw[i][u] = col[j][u] = area[index][u] = true;
//                 }
//             }
//         }
//         BackTracing37(board, raw, col, area, 0, 0);
//     }
// };

class Solution {
public:
    bool IsVaild(std::vector<std::vector<char>> &board, int row, int col, int val) {
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == val) return false;
        }

        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == val) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

    bool BackTracing37(std::vector<std::vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (IsVaild(board, i, j, k)) {
                            board[i][j] = k;
                            if (BackTracing37(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(std::vector<std::vector<char>> &board) {
        BackTracing37(board);
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    sol.solveSudoku(board);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
