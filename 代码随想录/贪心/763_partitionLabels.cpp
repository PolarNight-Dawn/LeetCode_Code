#include <iostream>
#include <vector>

//
// Created by polarnight on 23-10-23, 下午2:30.
//

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> res;

        std::vector<int> last_pos(26, 0);
        int len = s.size();
        for (int i = 0; i < len; i++) last_pos[s[i] - 'a'] = i;

        int start = 0, end = 0;
        for (int i = 0; i < len; i++) {
            end = std::max(end, last_pos[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return res;
    }
};

int main763() {
    std::string  s = "ababcbacadefegdehijhklij";

    Solution sol;
    std::vector<int> res = sol.partitionLabels(s);

    for (auto &vec : res) {
        std::cout << vec << " ";
    }
    std::cout << std::endl;

    return 0;
}