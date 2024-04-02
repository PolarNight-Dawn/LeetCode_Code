//
// Created by polarnight on 24-3-28, 下午7:14.
//

#include <iostream>
#include <vector>

using namespace std;

int mainyouyou02() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0, j = 0; i < n; i++, j = 0) {
        while (cin >> matrix[i][j]) {
            if (++j == m) break;
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;) {
            if (j == m) {
                if (i < n - 1) i++, j = 0;
                else break;
            }
            if (j == m - 1) {
                if (matrix[i][j] == 0) res++;
                if (i < n - 1)
                    i++, j = 0;
                else break;
            }
            if (matrix[i][j] == 1 && matrix[i][j + 1] == 1) {
                j += 2;
                continue;
            }
            j += 2, res++;
        }
    }

    printf("%d", res);
}
