#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-20, 下午2:45.
//

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        int m = s.size();
        if (n != m) return false;

        int cnt = 0;
        for (auto &word : words)
            if (word[0] != s[cnt++]) return false;

        return true;
    }
};

int main2312202828() {
    vector<string> words = {"alice","bob","charlie"};
    string s = "abc";

    Solution sol;
    cout << sol.isAcronym(words, s);

    return 0;
}