#include <iostream>
#include <unordered_set>

//
// Created by polarnight on 23-9-14, 下午2:12.
//

class Solution {
public:
    int get_sum(int n ) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    //! \哈希集合
    // bool isHappy(int n) {
    //     std::unordered_set<int> set;
    //     while (true) {
    //         int sum = get_sum(n);
    //         if (sum == 1) return true;
    //         else {
    //             if (set.find(sum) != set.end()) return false;
    //             else set.insert(sum);
    //         }
    //         n = sum;
    //     }

    //! \快慢指针
    // 这道题不建议使用哈希集合去记录每次的计算结果，因为这个集合可能大到无法存储
    // 同样此题也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃
    // 不要因为本题给出的数据类型是 int 型而投机取巧
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = get_sum(slow);
            fast = get_sum(fast);
            fast = get_sum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};

int main202() {
    int n = 19;

    Solution sol;
    std::cout << sol.isHappy(n);

    return 0;
}