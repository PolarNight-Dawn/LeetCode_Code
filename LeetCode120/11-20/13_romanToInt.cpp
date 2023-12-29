#include <iostream>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-4-23.
//

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> hash_map = {{"M",  1000},
                                               {"CM", 900},
                                               {"D",  500},
                                               {"CD", 400},
                                               {"C",  100},
                                               {"XC", 90},
                                               {"L",  50},
                                               {"XL", 40},
                                               {"X",  10},
                                               {"IX", 9},
                                               {"V",  5},
                                               {"IV", 4},
                                               {"I",  1},
        };

        int len = s.size();
        int i = 0, num = 0;
        string str = "";

        while (i < len) {
            str = s[i];
            if (hash_map.find(str) != hash_map.end()) {
                str += s[i + 1];
                if (hash_map.find(str) != hash_map.end()) {
                    num += hash_map[str];
                    i++;
                } else {
                    str.pop_back();
                    num += hash_map[str];
                }
            }
            i++;
        }
        return num;
    }
};

int main13() {
    string s = "MCMXCIV";

    Solution sol;
    cout << sol.romanToInt(s);

    return 0;
}
