#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

//
// Created by polarnight on 23-9-25, 下午5:33.
//

class Solution {
public:
    // 哈希 set和map混合 时间复杂度为O(n)
    // std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    //     std::vector<int> tmp;
    //     std::vector<int> res;
    //     std::unordered_map<int, int> map;
    //
    //     for (auto &vec : nums) {
    //         map[vec]++;
    //         if (std::find(tmp.begin(), tmp.end(), vec) == tmp.end()) tmp.push_back(vec);
    //     }
    //
    //     while (k--) {
    //         int max_num = 0, key = 0;
    //         for (auto &vec : tmp) {
    //             max_num = std::max(max_num, map[vec]);
    //             key = (max_num == map[vec]) ? vec : key;
    //         }
    //         res.push_back(key);
    //         map.erase(key);
    //     }
    //
    //     return res;
    // }

    // 优先队列 大顶堆
    // 时间复杂度O(n) + O(n * log n) + O(k * log n) = O(n * log n + k * log n) = O((n + k) * log n)
    // std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    //     std::unordered_map<int, int> map;
    //
    //     for (auto &vec : nums) {
    //         map[vec]++;
    //     }
    //
    //     auto MyCompare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    //         return a.second < b.second;
    //     };
    //
    //     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(MyCompare)> pri_que(MyCompare);
    //     for (auto &vec : map) {
    //         pri_que.push(vec);
    //     }
    //
    //     std::vector<int> res;
    //     while (k--) {
    //         res.push_back(pri_que.top().first);
    //         pri_que.pop();
    //     }
    //
    //     return res;
    // }

    // 优化代码 优先队列 小顶堆
    // 时间复杂度O(n) + O(n * log k) + O(k * log k) = O(n * log k)
    // 只保留 k 个元素，超处的元素就弹出
    // 因为小顶堆每次将最小的元素弹出，所以最后小顶堆里的就是最大的 k 个元素
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> map;
        for (auto &vec: nums) {
            map[vec]++;
        }

        auto MyCompare = [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
            return a.second > b.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(MyCompare)> pri_que(MyCompare);
        for (auto &vec: map) {
            pri_que.push(vec);
            if (pri_que.size() > k) pri_que.pop();
        }

        std::vector<int> res;
        while (!pri_que.empty()) {
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return res;
    }
};

int main347() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution sol;
    std::vector<int> res = sol.topKFrequent(nums, k);

    for (auto &vec: res) {
        std::cout << vec << " ";
    }

    return 0;
}