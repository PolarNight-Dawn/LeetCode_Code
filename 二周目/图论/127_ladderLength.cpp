#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-11-22, 下午2:38.
//

class Solution {
public:
    bool IsValid(std::string &now_word, std::string &next_word) {
        if (now_word.size() != next_word.size()) return false;
        if (now_word == next_word) return false;

        int count = 0;
        for (int i = 0; i < now_word.size(); i++) {
            if (now_word[i] != next_word[i]) count++;
        }

        return count <= 1;
    }

    void dfs127(std::string &now_word, std::string &end_word, std::vector<std::string> &word_list, std::vector<int> &result, std::vector<int> &visited, int ans) {
        if (now_word == end_word) {
            result.push_back(ans);
            return;
        }

        for (int i = 0; i < word_list.size(); i++) {
            if (std::find(visited.begin(), visited.end(), i) == visited.end()) {
                std::string next_word = word_list[i];
                if (!IsValid(now_word, next_word)) continue;
                visited.push_back(i);
                dfs127(next_word, end_word, word_list, result, visited, ans + 1);
                visited.pop_back();
            }
        }
    }

    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        std::vector<int> result;
        std::vector<int> visited;

        dfs127(beginWord, endWord, wordList, result, visited, 1);

        int ans = INT32_MAX;
        for (auto &vec : result) {
            ans = std::min(ans, vec);
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};

int main127() {
    std::string beginWord = "hot";
    std::string endWord = "dog";
    std::vector<std::string> wordList = {"hot","dog","dot"};

    Solution sol;
    std::cout << sol.ladderLength(beginWord, endWord, wordList);

    return 0;
}