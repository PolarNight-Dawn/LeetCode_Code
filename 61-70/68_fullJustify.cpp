#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-8.
//

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> ans;
        int n = words.size();
        std::vector<std::string> list;
        for (int i = 0; i < n; ) {
            // list stores all words in the current line
            list.clear();
            list.push_back(words[i]);
            int cur = words[i++].length();
            while (i < n && cur + 1 + words[i].length() <= maxWidth) {
                cur += 1 + words[i].length();
                list.push_back(words[i++]);
            }

            // Current line is the last line, special case for left alignment
            if (i == n) {
                std::string sb = list[0];
                for (int k = 1; k < list.size(); k++) {
                    sb += " " + list[k];
                }
                while (sb.length() < maxWidth) sb += " ";
                ans.push_back(sb);
                break;
            }

            // If the current line has only one word, special case for left alignment
            int cnt = list.size();
            if (cnt == 1) {
                std::string str = list[0];
                while (str.length() != maxWidth) str += " ";
                ans.push_back(str);
                continue;
            }

            // General case
            int wordWidth = cur - (cnt - 1);
            int spaceWidth = maxWidth - wordWidth;
            int spaceItemWidth = spaceWidth / (cnt - 1);
            std::string spaceItem = "";
            for (int k = 0; k < spaceItemWidth; k++) spaceItem += " ";
            std::string sb = "";
            for (int k = 0, sum = 0; k < cnt; k++) {
                std::string item = list[k];
                sb += item;
                if (k == cnt - 1) break;
                sb += spaceItem;
                sum += spaceItemWidth;
                int remain = cnt - k - 1 - 1;
                if (remain * spaceItemWidth + sum < spaceWidth) {
                    sb += " ";
                    sum++;
                }
            }
            ans.push_back(sb);
        }
        return ans;
    }
};


int main68() {
    std::vector<std::string> words = {"ask","not","what","your","country","can","do","for","you",
                                      "ask","what","you","can","do","for","your","country"};
    std::vector<std::string> res;
    int maxWidth = 16;

    Solution sol;
    res = sol.fullJustify(words, maxWidth);

    for (auto &vec: res) {
        std::cout << vec << ";" << std::endl;
    }

    return 0;
}