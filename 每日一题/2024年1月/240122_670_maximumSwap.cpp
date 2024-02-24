#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//
// Created by polarnight on 24-1-22, 下午3:21.
//

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size() - 1;
        int p = -1, q = 0, max_idx = n;

        for (int i = n - 1; i >= 0; i--) {
            if (str[i] > str[max_idx]) max_idx = i;
            else if (str[i] < str[max_idx]) p = i, q = max_idx;
        }
        if (p == -1) return num;
        swap(str[p], str[q]);
        return stoi(str);
    }

};

int main240122() {
    int num = 98368;

    Solution sol;
    cout << sol.maximumSwap(num);

    return 0;
}