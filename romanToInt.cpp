#include <iostream>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-4-23.
//

class Solution {
public:
    int romanToInt(string s) {
        /*unordered_map<char, int> hash_map = {{'I', 1},
                                             {'V', 5},
                                             {'X', 10},
                                             {'L', 50},
                                             {'C', 100},
                                             {'D', 500},
                                             {'M', 1000}};
*/
        int len = s.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    sum += 4;
                    i = i + 1;
                } else if (s[i + 1] == 'X') {
                    sum += 9;
                    i = i + 1;
                } else {
                    sum += 1;
                }
            } else if (s[i] == 'V') {
                sum += 5;
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    sum += 40;
                    i = i + 1;
                } else if (s[i + 1] == 'C') {
                    sum += 90;
                    i = i + 1;
                } else {
                    sum += 10;
                }
            } else if (s[i] == 'L') {
                sum += 50;
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    sum += 400;
                    i = i + 1;
                } else if (s[i + 1] == 'M') {
                    sum += 900;
                    i = i + 1;
                } else {
                    sum += 100;
                }
            } else if (s[i] == 'D') {
                sum += 500;
            } else if (s[i] == 'M') {
                sum += 1000;
            }
        }
        return sum;
    }
};

int main13() {
    string s = "III";

    Solution sol;
    cout << sol.romanToInt(s);

    return 0;
}
