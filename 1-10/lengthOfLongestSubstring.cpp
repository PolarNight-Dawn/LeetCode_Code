#include <iostream>
#include <unordered_map>

using namespace std;
//
// Created by polarnight on 23-4-11.
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int ans = 0;
        int left = 0, right = 0;
        int n = s.size();
        while (right < n) {
            char c = s[right];
            if (hash.find(c) != hash.end() && hash[c] >= left) {
                left = hash[c] + 1;
            }
            hash[c] = right;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};



int main03 () {
    Solution sol;
    string s = "abcdeafghia";
    cout << sol.lengthOfLongestSubstring(s);

    return 0;
}