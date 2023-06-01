#include <iostream>
#include <vector>

using namespace std;
//
// Created by polarnight on 23-4-13.
//

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        vector<vector<char>> buffer (numRows, vector<char>(n, '\0'));

        if (numRows == 1) {
            return s;
        }
        //Z字储存
        int cnt = 0;
        bool eof = false;
        while (cnt <= n - 1) {
            for (int i = 0; i < n; i++) {
                if (eof) {
                    break;
                }
                int jud = i % (numRows - 1);
                if (jud == 0) {
                    for (int j = 0; j < numRows; j++) {
                        if (cnt > n - 1) {
                            eof = true;
                            break;
                        }
                        buffer[j][i] = s[cnt];
                        cnt++;
                    }
                } else {
                    if (cnt > n - 1) {
                        eof = true;
                        break;
                    }
                    buffer[numRows - jud - 1][i] = s[cnt];
                    cnt++;
                }
            }
        }

        //顺序遍历
        string str = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < n; j++) {
                if (buffer[i][j] != '\0') {
                    str.push_back(buffer[i][j]);
                }
            }
        }
        return str;
    }
};

int main06 () {
    string s = "ABCDEF";
    int numRows = 2;

    Solution sol;
    cout << sol.convert(s, numRows);
}