#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-20, 下午3:55.
//

class Solution {
public:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs130(std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &visited, int x, int y) {
        if (visited[x][y] || board[x][y] == 'X') return;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= board.size() || next_y >= board[0].size()) continue;
            dfs130(board, visited, next_x, next_y);
        }
    }

    void solve(std::vector<std::vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs130(board, visited, i, 0);
            dfs130(board, visited, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs130(board, visited, 0, j);
            dfs130(board, visited, m - 1, j);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
                    dfs130(board, visited, i, j);
            }
        }
    }
};

int main130() {
    std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'},
                                            {'X', 'O', 'O', 'X'},
                                            {'X', 'X', 'O', 'X'},
                                            {'X', 'O', 'X', 'X'}};

    Solution sol;
    sol.solve(board);

    for (auto &tmp: board) {
        for (auto &vec: tmp) {
            std::cout << vec << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}