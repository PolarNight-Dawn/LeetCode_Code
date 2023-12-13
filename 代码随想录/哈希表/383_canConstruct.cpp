#include <iostream>
#include <vector>

//
// Created by polarnight on 23-9-12, 下午2:42.
//

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        std::vector<int> hash(26, 0);

        for (auto &vec : magazine) {
            hash[vec - 'a']++;
        }

        for (auto &vec : ransomNote) {
            hash[vec - 'a']--;
            if (hash[vec - 'a'] < 0) return false;
        }

        return true;
    }
};

int main383() {
    std::string ransomNote = "a";
    std::string magazine = "b";

    Solution sol;
    std::cout << sol.canConstruct(ransomNote, magazine);

    return 0;
}