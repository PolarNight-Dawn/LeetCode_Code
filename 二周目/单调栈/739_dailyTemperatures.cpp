#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

//
// Created by polarnight on 23-11-14, 下午2:31.
//

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::stack<int> sta;
        std::vector<int> answer(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!sta.empty() && temperatures[i] > temperatures[sta.top()]) sta.pop();
            if (!sta.empty()) answer[i] = sta.top() - i;
            sta.push(i);
        }
        return answer;
    }
};

int main739() {
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution sol;
    std::vector<int> answer = sol.dailyTemperatures(temperatures);

    for (auto &vec: answer) {
        std::cout << vec << " ";
    }
    std::cout << std::endl;

    return 0;
}