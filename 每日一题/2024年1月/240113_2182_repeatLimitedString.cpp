#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//
// Created by polarnight on 24-1-13, 下午3:23.
//

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        priority_queue<char> pri_que;

        for (auto tmp: s)
            pri_que.push(tmp);

        int cnt = 0;
        string str, temp;
        bool flag = false;
        char c = pri_que.top();
        while (!pri_que.empty()) {
            if (pri_que.top() != c) cnt = 0;
            else cnt++;
            if (cnt > repeatLimit) {
                flag = true;
                temp = pri_que.top();
                pri_que.pop();
                continue;
            }
            str += pri_que.top();
            pri_que.pop();
            if (flag) {
                str += temp;
                flag = false;
            }
        }
        return str;
    }
};

int main2401132182() {
    string s = "cczazcc";
    int repeatLimit = 3;

    Solution sol;
    cout << sol.repeatLimitedString(s, repeatLimit);

    return 0;
}
