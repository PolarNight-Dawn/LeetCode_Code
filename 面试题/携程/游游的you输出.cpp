//
// Created by polarnight on 24-3-28, 下午7:05.
//

#include <iostream>

using namespace std;

int mainyouyou01() {
    int a;
    cin >> a;

    string str;
    string str1 = "you";
    string str2 = "uoy";

    int cnt = 1;
    while (cnt <= a) {
        int jude = cnt % 2;
        cnt++;
        if (jude != 0) {
            str += str1;
            continue;
        }
        str += str2;
    }

    cout << str << endl;
}