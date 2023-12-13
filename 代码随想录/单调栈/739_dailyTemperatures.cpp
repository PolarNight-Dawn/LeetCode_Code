#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
//
// Created by polarnight on 23-11-14, 下午2:31.
//

class Solution {
public:
    // std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    //     std::stack<int> sta;
    //     std::vector<int> answer(temperatures.size(), 0);
    //
    //     for (int i = temperatures.size() - 1; i >= 0; i--) {
    //         while (!sta.empty() && temperatures[i] > temperatures[sta.top()]) sta.pop();
    //         if (!sta.empty()) answer[i] = sta.top() - i;
    //         sta.push(i);
    //     }
    //     return answer;
    // }

    // 代码随想录二刷
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        int n = temperatures.size();
        stack<int> sta;
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++) {
            while (!sta.empty() && temperatures[sta.top()] < temperatures[i]) {
                answer[sta.top()] = i - sta.top();
                sta.pop();
            }
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