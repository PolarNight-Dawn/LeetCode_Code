#include <iostream>

//
// Created by polarnight on 23-9-21, 下午5:25.
//

class Solution {
public:
    //! \TLE 没有具体分析时间复杂度
    int isPrefixOfWord(std::string sentence, std::string searchWord) {
        int word_cnt = 1;
        int right = 0;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                word_cnt++;
                if (sentence.size() - i < searchWord.size()) return -1;
            }
            if (i == 0 || sentence[i - 1] == ' ') {
                if (sentence.size() - i < searchWord.size()) continue;
                while (sentence[i] == searchWord[right]) {
                    i++, right++;
                    if (right == searchWord.size()) return word_cnt;
                }
                right = 0;
                //! 好像没有这行代码前没有出现\TLE，但是那是错误解法
                i--;
            }
        }

        return -1;
    }
};

int main1445() {
    std::string sentence = "hellohello hellohellohello";
    std::string searchWord = "ell";

    Solution sol;
    std::cout << sol.isPrefixOfWord(sentence, searchWord);

    return 0;
}