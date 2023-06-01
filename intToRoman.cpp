#include <iostream>
#include <map>

using namespace std;
//
// Created by polarnight on 23-4-19.
//

class Solution {
public:
    string intToRoman(int num) {
        map<int, char> hash = {{1,    'I'},
                               {5,    'V'},
                               {10,   'X'},
                               {50,   'L'},
                               {100,  'C'},
                               {500,  'D'},
                               {1000, 'M'}};

        string str = "";
        while (num > 0) {
            if (num >= 1000) {
                char c = hash.at(1000);
                str = str + c;
                num -= 1000;
            } else if (num >= 500) {
                if (num >= 900) {
                    char c1,c2;
                    c1 = hash.at(100);
                    c2 = hash.at(1000);
                    str = str + c1 + c2;
                    num -= 900;
                } else {
                    char c;
                    c = hash.at(500);
                    str = str + c;
                    num -= 500;
                }
            } else if (num >= 100) {
                if (num >= 400) {
                    char c1, c2;
                    c1 = hash.at(100);
                    c2 = hash.at(500);
                    str = str + c1 + c2;
                    num -= 400;
                } else {
                    char c;
                    c = hash.at(100);
                    str = str + c;
                    num -= 100;
                }
            } else if (num >= 50) {
                if (num >= 90) {
                    char c1, c2;
                    c1 = hash.at(10);
                    c2 = hash.at(100);
                    str = str + c1 + c2;
                    num -= 90;
                } else {
                    char c;
                    c = hash.at(50);
                    str = str + c;
                    num -= 50;
                }
            } else if (num >= 10) {
                if (num >= 40) {
                    char c1, c2;
                    c1 = hash.at(10);
                    c2 = hash.at(50);
                    str = str + c1 + c2;
                    num -= 40;
                } else {
                    char c;
                    c = hash.at(10);
                    str = str + c;
                    num -= 10;
                }
            } else if (num >= 5) {
                if (num >= 9) {
                    char c1, c2;
                    c1 = hash.at(1);
                    c2 = hash.at(10);
                    str = str + c1 + c2;
                    num -= 9;
                } else {
                    char c;
                    c = hash.at(5);
                    str = str + c;
                    num -= 5;
                }
            } else if (num >= 1) {
                if (num >= 4) {
                    char c1, c2;
                    c1 = hash.at(1);
                    c2 = hash.at(5);
                    str = str + c1 + c2;
                    num -= 4;
                } else {
                    char c;
                    c = hash.at(1);
                    str = str + c;
                    num -= 1;
                }
            }
        }
        return str;
    }
};

int main12() {
    int num = 1994;

    Solution sol;
    cout << sol.intToRoman(num);

    return 0;
}