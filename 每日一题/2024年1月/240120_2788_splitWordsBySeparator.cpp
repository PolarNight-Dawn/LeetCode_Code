#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//
// Created by polarnight on 24-1-20, 下午3:01.
//

class Solution {
public:
    //! \基础的实现方式
    //! 时间复杂度O(n ^ 2)
    // vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
    //     int n = words.size();
    //     vector<vector<int>> cnt(n);
    //     vector<string> result;
    //
    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < words[i].size(); j++)
    //             if (words[i][j] == separator) cnt[i].push_back(j);
    //
    //
    //     for (int i = 0; i < n; i++) {
    //         int temp = -1, len = cnt[i].size();
    //         if (len == 0) result.push_back(words[i]);
    //         for (int j = 0; j < len; j++) {
    //             string str = words[i].substr(temp + 1, cnt[i][j] - temp - 1);
    //             temp = cnt[i][j];
    //             if (str != "") result.push_back(str);
    //             if (j == len - 1 && temp != words[i].size() - 1) result.push_back(words[i].substr(temp + 1));
    //         }
    //     }
    //
    //     return result;
    // }

    //! \调用库函数
    vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
        vector<string> result;

        for (auto &word : words) {
            stringstream s(word);
            string str;
            while (getline(s, str, separator))
                if (!str.empty()) result.push_back(str);
        }
        return result;
    }
};

int main2401202788() {
    vector<string> words = {"#,"};
    char separator = '#';

    Solution sol;
    auto result = sol.splitWordsBySeparator(words, separator);

    for (auto &res: result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}