#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-27, 下午2:11.
//


class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();

        function<int(int, int)> Compare = [&](int play1, int play2) -> int {
            if (play1 > play2) return 1;
            else if (play1 < play2) return 2;
            else return 0;
        };

        function<int(int, vector<int>)> get_sum = [&](int ans, vector<int> play) -> int {
            if (play[0] == 10) ans += play[1] * 2;
            else ans += play[1];
            for (int i = 2; i < n; i++) {
                if (play[i - 1] == 10 || play[i - 2] == 10) ans += play[i] * 2;
                else ans += play[i];
            }
            return ans;
        };

        if (n == 1) return Compare(player1[0], player2[0]);
        int score_player1 = player1[0], score_player2 = player2[0];
        score_player1 = get_sum(score_player1, player1);
        score_player2 = get_sum(score_player2, player2);
        return Compare(score_player1, score_player2);
    }
};

int main231227_2660() {
    vector<int> player1 = {2,3};
    vector<int> player2 = {4,1};

    Solution sol;
    cout << sol.isWinner(player1, player2);

    return 0;
}