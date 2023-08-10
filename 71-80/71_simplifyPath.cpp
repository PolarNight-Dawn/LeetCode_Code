#include <iostream>
#include <vector>
#include <sstream>

//
// Created by polarnight on 23-8-10.
//

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> tokens;

        std::istringstream iss(path);
        std::string token;
        while (getline(iss, token, '/')) {
            if (token == "..") {
                if (!tokens.empty()) tokens.pop_back();
            } else if (token != "." && !token.empty()) {
                tokens.push_back(token);
            }
        }

        std::string res = "/";
        for (auto &vec : tokens) {
            res += vec + "/";
        }

        if (res.size() > 1 && res.back() == '/') res.pop_back();

        return res;
    }
};

int main() {
    std::string path = "/home//foo/";

    Solution sol;
    std::cout << sol.simplifyPath(path);

    return 0;
}