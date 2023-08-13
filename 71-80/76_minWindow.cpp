#include <iostream>
#include <unordered_map>

//
// Created by polarnight on 23-8-13.
//

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::string ansString;
        if (s.size() < t.size()) return ansString;
        std::unordered_map<char, int> hashS;
        std::unordered_map<char, int> hashT;

        for (auto &vec : t) hashT[vec]++;

        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hashS[s[i]]++;
            if (hashS[s[i]] <= hashT[s[i]]) cnt++;

            while (hashS[s[j]] > hashT[s[j]]) hashS[s[j++]]--;
            if (cnt == t.size()) {
                if (ansString.empty() || i - j < ansString.size()) {
                    ansString = s.substr(j, i - j + 1);
                }
            }
        }

        return ansString;
    }
};

int main() {
    std::string s = "AD";
    std::string t = "ABC";

    Solution sol;
    std::cout << sol.minWindow(s, t);

    return 0;
}