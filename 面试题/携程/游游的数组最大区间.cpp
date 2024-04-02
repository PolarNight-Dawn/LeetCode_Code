//
// Created by polarnight on 24-3-28, 下午8:04.
//

#include <iostream>
#include <vector>

using namespace std;

int mainyouyou03() {
    int n;
    cin >> n;

    vector<int> group(n);
    int cnt = 0;
    while (cin >> group[cnt]) {
        if (++cnt == n) break;
    }

    vector<int> dp(n, INT32_MIN), status(n);
    dp[0] = group[0] >= 0 ? group[0] : group[0] / 2;
    status[0] = dp[0] == group[0] / 2 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        int jude = group[i] % 2;
        if (jude == 0) {
            int tmp1 = 0;
            if (i > 0 && status[i - 1] == 1) tmp1 = dp[i - 1] + group[i] / 2;
            dp[i] = dp[i - 1] + group[i];

            int tmp2 = tmp1;
            if (i > 0 && group[i] < 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (group[j] % 2 != 0) break;
                    if (status[j] == 0) tmp2 -= group[j] / 2;
                    else break;
                }
            }
            tmp1 = max(tmp1, tmp2);
            dp[i] = max(tmp1, dp[i]);
            status[i] = dp[i] == tmp1 ? 1 : 0;
        } else {
            dp[i] += dp[i - 1];
        }
    }

    cout << dp[n - 1] << endl;
}
// 64 位输出请用 printf("%lld")