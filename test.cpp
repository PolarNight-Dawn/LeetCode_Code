#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-4-14.
//

int main00() {
    vector<char> vec = {'a', 'b', 'b'};

    vec.erase(remove(vec.begin(), vec.end(), 'b'), vec.end());

    for (auto &temp : vec) {
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}

/*if (s[i] == p[stamp1 + 1]){
string s3 = s.substr(i);
string s4 = p.substr(stamp1 + 1);
if (s3 == s4) {
return true;
} else {
return false;
}
}*/


