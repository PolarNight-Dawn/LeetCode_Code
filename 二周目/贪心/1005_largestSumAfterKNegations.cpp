#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//
// Created by polarnight on 23-10-18, 下午3:22.
//

class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    // 利用 STL 库中的 std::min_element 函数确定最小值
    // int largestSumAfterKNegations(std::vector<int> &nums, int k) {
    //     std::sort(nums.begin(), nums.end());
    //
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (k == 0) break;
    //         if (nums[i] <= 0) {
    //             nums[i] *= -1;
    //             k--;
    //         } else break;
    //     }
    //     if (k % 2 != 0) {
    //         auto min = std::min_element(nums.begin(), nums.end());
    //         *min *= -1;
    //     }
    //
    //     int sum = 0;
    //     for (auto &vec: nums) sum += vec;
    //     return sum;
    // }

    // 利用 cmp 比较函数将值的绝对值降序排列
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};

int main() {
    std::vector<int> nums = {-2, 9, -9, 8, 4};
    int k = 3;

    Solution sol;
    std::cout << sol.largestSumAfterKNegations(nums, k);

    return 0;
}