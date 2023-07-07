#include <iostream>
#include <vector>
#include <unordered_set>

//
// Created by polarnight on 23-6-27.
//

class Solution {
public:
    int matchTwoStr(std::string str, std::string s) {
        int n = 0, res = 0;
        int lenStr = str.size();
        int lenS = s.size();
        while (n < lenS) {
            if (str[0] == s[n]) {
                res = n;
                int left = 1;
                int right = n + 1;
                if (left == lenStr) return res;
                while (str[left] == s[right] && right < lenS) {
                    left++;
                    right++;
                    if (left == lenStr) return res;
                }
                n = res + 1;
            } else {
                n++;
            }
        }
        return -1;
    }

    void backTracking(std::vector<int> &res, std::string s, std::vector<std::string> words,
                      std::string str, int wordsSize, int words0Size) {
        for (int i = 0; i < words.size(); i++) {
            str += words[i];
            int cnt = 0;
            if (str.size() == wordsSize) cnt = matchTwoStr(str, s);
            /*if (str == "foobar") {
                std::cout << "foobar";
            }*/
            if (cnt == -1) break;
            if (str.size() == wordsSize) {
                res.push_back(cnt);
                while (cnt + 2 * words0Size < s.size()) {
                    std::string sS = s.substr(cnt + words0Size);
                    int cnt1 = matchTwoStr(str, sS);
                    if (cnt1 == -1) break;
                    cnt += cnt1 + words0Size;
                    res.push_back(cnt);
                }
                return;
            }
            std::vector<std::string> word = words;
            word.erase(word.begin() + i);
            backTracking(res, s, word, str, wordsSize, words0Size);
            str.erase(str.end() - words0Size, str.end());
        }
    }

    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
        std::vector<int> res;
        int words0Size = words[0].size();
        int wordsSize = words.size() * words0Size;
        if (wordsSize > s.size()) return res;

        std::string str;
        backTracking(res, s, words, str, wordsSize, words0Size);
        std::unordered_set<int> vec(res.begin(), res.end());
        res.assign(vec.begin(), vec.end());
        return res;
    }
};

int main30() {
    std::string s = "aaaaaaaaaaaaaa";
    std::vector<std::string> words = {"aa", "aa"};
    std::vector<int> res;

    Solution sol;
    res = sol.findSubstring(s, words);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }

    return 0;

}