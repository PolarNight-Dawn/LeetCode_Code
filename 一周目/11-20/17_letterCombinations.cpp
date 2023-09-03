#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-5-8.
//

class Solution {
private:
    unordered_map<int, string> map = {{0, ""},
                                      {1, ""},
                                      {2, "abc"},
                                      {3, "def"},
                                      {4, "ghi"},
                                      {5, "jkl"},
                                      {6, "mno"},
                                      {7, "pqrs"},
                                      {8, "tuv"},
                                      {9, "wxyz"},};
public:
    vector<string> res;
    string str;

    void backTracking(string digits, int index) {
        if (index == digits.size()) {
            res.push_back(str);
            return;
        }

        int cnt = digits[index] - '0';
        string letter = map[cnt];
        for (int i = 0; i < letter.size(); i++) {
            str.push_back(letter[i]);
            backTracking(digits, index + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        str.clear();
        res.clear();
        if (digits.size() == 0) return res;

        backTracking(digits, 0);

        return res;
    }
};

int main17() {
    string digits = "23";

    Solution sol;
    vector<string> vec = sol.letterCombinations(digits);

    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) cout << ", ";
        cout << "\"" << vec[i] << "\"";
    }
    cout << "]" << endl;

    return 0;
}