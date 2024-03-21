//
// Created by polarnight on 24-3-21, 下午7:42.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker() : freq(100001), freq_cnt(100001) {

    }

    void add(int number) {
        --freq_cnt[freq[number]];
        ++freq_cnt[++freq[number]];
    }

    void deleteOne(int number) {
        if (!freq[number]) return;
        --freq_cnt[freq[number]];
        ++freq_cnt[--freq[number]];
    }

    /* 双哈希表可以实现O(1) 的查找效率 */
    bool hasFrequency(int frequency) {
        return freq_cnt[frequency];
    }

private:
    /* 哈希表 freq 表示 number 的出现频率， 哈希表 freq_cnt 表示 出现频率的频率 */
    unordered_map<int, int> freq;
    unordered_map<int, int> freq_cnt;
};

int main() {
    auto *obj = new FrequencyTracker();

    obj->add(2);
    obj->add(2);
    obj->add(3);
    obj->add(3);
    obj->deleteOne(2);
    cout << obj->hasFrequency(2);

    delete obj;

    return 0;
}