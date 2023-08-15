#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-8-15.
//

class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        if (board.size() == 0) return false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(std::vector<std::vector<char>> &board, std::string &word, int i, int j, int length) {
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || length >= word.size() ||
            word[length] != board[i][j]) {
            return false;
        }
        if (length == word.size() - 1 && word[length] == board[i][j]) {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        bool flag = dfs(board, word, i, j + 1, length + 1) || dfs(board, word, i, j - 1, length + 1) ||
                    dfs(board, word, i + 1, j, length + 1) || dfs(board, word, i - 1, j, length + 1);
        board[i][j] = temp;  // 标记过的点恢复原状，以便进行下一次搜索
        return flag;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'a', 'b'},
                                            {'c', 'd'}};
    std::string word = "cdba";

    Solution sol;
    std::cout << sol.exist(board, word);

    return 0;
}