#include <iostream>
#include <vector>
#include <stack>

//
// Created by polarnight on 23-9-24, 下午6:59.
//

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        if (tokens.size() == 1) return std::stoi(tokens[0]);
        std::stack<int> sta;

        int ans = 0;
        for (auto &vec : tokens) {
            if (vec == "+" || vec == "-" || vec == "*" || vec == "/") {
                int operand_1 = sta.top();
                sta.pop();
                int operand_2 = sta.top();
                sta.pop();
                if (vec == "+") ans = operand_1 + operand_2;
                if (vec == "-") ans = operand_2 - operand_1;
                if (vec == "*") ans = operand_1 * operand_2;
                if (vec == "/") ans = operand_2 / operand_1;
                sta.push(ans);
            } else {
                sta.push(std::stoi(vec));
            }
        }

        return ans;
    }
};

int main() {
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    Solution sol;
    std::cout << sol.evalRPN(tokens);

    return 0;
}