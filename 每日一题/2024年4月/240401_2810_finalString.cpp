//
// Created by polarnight on 24-4-2, 下午3:56.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    /*! \直接模拟
     * \时间复杂度 O(n^2) */
    /*string finalString(string s) {
        auto it = find(s.begin(), s.end(), 'i');
        while (it != s.end()) {
            int cnt = distance(s.begin(), it);

            string str;
            for (int i = cnt - 1; i >= 0; i--)
                str += s[i];

            str += s.substr(cnt + 1);
            s = str;
            it = find(s.begin(), s.end(), 'i');
        }
        return s;
    }*/

    /*! \双端队列
     * \时间复杂度 O(n)*/
    string finalString(string s) {
        deque<char> deq;
        bool tail = true;
        for (auto &c: s) {
            if (c == 'i') tail = !tail;
            else if (tail) deq.push_back(c);
            else deq.push_front(c);
        }
        return tail ? string(deq.begin(), deq.end()) : string(deq.rbegin(), deq.rend());
    }
};

int main240401_2810() {
    string s = "string";

    Solution sol;
    cout << sol.finalString(s);

    return 0;
}