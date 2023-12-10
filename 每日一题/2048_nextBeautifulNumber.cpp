#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//
// Created by polarnight on 23-12-10, 下午1:26.
//

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int ans = 0;

        for (int i = n + 1; ; i++) {
            int digs[10] = {};
            bool ok = true;
            for (int num = i; num > 0; num /= 10) {
                int dig = num % 10;
                if (dig == 7 || dig == 8 || dig == 9) {
                    ok = false;
                    break;
                }
                digs[dig]++;
            }

            if (!ok) continue;

            for (int num = i; num > 0; num /= 10) {
                if (digs[num % 10] != num % 10) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    int n = 748601;

    Solution sol;
    cout << sol.nextBeautifulNumber(n);

    return 0;
}