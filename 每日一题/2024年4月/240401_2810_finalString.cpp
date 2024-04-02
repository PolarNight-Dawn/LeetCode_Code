//
// Created by polarnight on 24-4-2, 下午3:56.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string finalString(string s) {
        auto it = find(s.begin(), s.end(), 'i');
        while (it != s.end()) {
            int cnt = distance(s.begin(), it);

            string str;
            for (int i = cnt - 1; i >= 0; i--)
                str += s[i];

            str += s.substr(cnt + 1);
            s = str;
            it = find(s.begin(), s.end(), 'i');
        }
        return s;
    }
};

int main240401_2810() {
    string s = "string";

    Solution sol;
    cout << sol.finalString(s);

    return 0;
}