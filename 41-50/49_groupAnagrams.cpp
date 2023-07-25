#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

//
// Created by polarnight on 23-7-25.
//

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        int sub=0;
        std::string tmp;
        std::unordered_map<std::string,int> work;
        for(auto str:strs)
        {
            tmp=str;
            sort(tmp.begin(),tmp.end());
            if(work.count(tmp))
            {
                res[work[tmp]].push_back(str);
            }
            else
            {
                std::vector<std::string> vec(1,str);
                res.push_back(vec);
                work[tmp]=sub++;
            }
        }
        return res;
    }
};

int main() {
    std::vector<std::string> strs = {"ddddddddddg","dgggggggggg"};
    std::vector<std::vector<std::string>> res;

    Solution sol;
    res = sol.groupAnagrams(strs);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << ";" << std::endl;
    }
}