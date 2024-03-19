//
// Created by polarnight on 24-3-7, 下午4:37.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> div;

        long long sum = 0;
        for (auto &w : word) {
            sum = (sum * 10 + (w - '0')) % m;
            div.push_back((sum % m == 0) ? 1 : 0);
        }

        return div;
    }
};

int main2403072575() {
    string word = "91221181269244172125025075166510211202115152121212341281327";
    int m = 21;

    Solution sol;
    auto res = sol.divisibilityArray(word, m);

    for (auto &r: res) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}