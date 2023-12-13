#include <iostream>
#include <unordered_map>
#include <vector>

//
// Created by polarnight on 23-9-12, 下午3:11.
//

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        std::unordered_map<char, int> map_s;
        std::unordered_map<char, int> map_p;

        for (auto &vec : p) {
            map_p[vec]++;
        }

        int cnt = 0;
        int len = p.size();
        for (int i = 0; i < s.size(); i++) {
            if (map_p.count(s[i])) {
                map_s[s[i]]++;
                while (map_s[s[i]] > map_p[s[i]]) {
                    map_s[s[cnt]]--;
                    cnt++;
                }
                if (i - cnt + 1 == len) res.push_back(cnt);
            } else {
                while (cnt <= i) {
                    map_s[s[cnt]]--;
                    cnt++;
                }
            }
        }

        return res;
    }
};

int main438() {
    std::string  s = "cbaebabacd";
    std::string p = "abc";

    Solution sol;
    std::vector<int> res = sol.findAnagrams(s, p);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }

    return 0;
}