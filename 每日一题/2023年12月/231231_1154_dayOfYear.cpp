#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//
// Created by polarnight on 23-12-31, 下午2:12.
//

class Solution {
public:
    // int dayOfYear(string date) {
    //     vector<int> month_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    //
    //     int ans = 0, day = 0, month = 0, year = 0;
    //     for (int i = 8; i < 10; i++)
    //         day += (date[i] - '0') * pow(10, 9 - i);
    //     ans += day;
    //
    //     for (int i = 5; i < 7; i++)
    //         month += (date[i] - '0') * pow(10, 6 - i);
    //     for (int i = 1; i < month; i++)
    //         ans += month_day[i - 1];
    //
    //     for (int i = 0; i < 4; i++)
    //         year += (date[i] - '0') * pow(10, 3 - i);
    //     if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month >= 3) ans++;
    //     return  ans;
    // }

    //! \代码优化
    int dayOfYear(string date) {
        int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        int ans = day;
        for (int i = 0; i < month - 1; i++)
            ans += month_day[i];

        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month >= 3) ans++;
        return ans;
    }
};

int main2312311154() {
    string date = "2012-01-02";

    Solution sol;
    cout << sol.dayOfYear(date);

    return 0;
}