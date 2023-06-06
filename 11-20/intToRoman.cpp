#include <iostream>

using namespace std;
//
// Created by polarnight on 23-4-19.
//

class Solution {
public:
    string intToRoman(int num) {
        pair<int, string> hash[] = {{1000, "M"},
                                  {900,  "CM"},
                                  {500,  "D"},
                                  {400,  "CD"},
                                  {100,  "C"},
                                  {90,   "XC"},
                                  {50,   "L"},
                                  {40,   "XL"},
                                  {10,   "X"},
                                  {9,    "IX"},
                                  {5,    "V"},
                                  {4,    "IV"},
                                  {1,    "I"},
        };

        string str = "";
        for (auto &[value, string]: hash) {
            while (num >= value) {
                num -= value;
                str += string;
            }
            if (num == 0) break;
        }
        return str;
    }
};

int main() {
    int num = 1994;

    Solution sol;
    cout << sol.intToRoman(num);

    return 0;
}