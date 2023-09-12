#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-12, 下午2:17.
//

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        std::vector<int> hash(26, 0);

        for (auto &vec: s) {
            hash[vec - 'a']++;
        }

        for (auto &vec : t) {
            hash[vec - 'a']--;
            if (hash[vec] < 0) return false;
        }

        return true;
    }
};

int main242() {
    std::string s = "anagram";
    std::string t = "nagaram";

    Solution sol;
    std::cout << sol.isAnagram(s, t);

    return 0;
}