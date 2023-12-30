#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-12-30, 下午3:04.
//

class Solution {
public:
    // string dayOfTheWeek(int day, int month, int year) {
    //     vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    //     vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    //
    //     int days = 365 * (year - 1971) + (year - 1969) / 4;
    //
    //     for (int i = 0; i < month - 1; i++) days += month_days[i];
    //     if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) days++;
    //
    //     days += day;
    //
    //     return week[(days + 4) % 7];
    // }

    //! \调库
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        tm dt = {0, 0, 0, day, month - 1, year - 1900};
        time_t t = mktime(&dt);
        return week[localtime(&t)->tm_wday];
    }
};

int main2312301185() {
    int day = 21, month = 12, year = 1980;

    Solution sol;
    cout << sol.dayOfTheWeek(day, month, year);

    return 0;
}