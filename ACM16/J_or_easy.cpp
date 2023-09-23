#include <iostream>
#include <bitset>
#include <chrono>
#include <vector>

int mainJ() {
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;

    std::vector<int> tmp;
    int cnt = 100;
    while (cnt--) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 2; i < n; ++i) {
            int count = static_cast<int>(std::bitset<32>(i).count());
            std::cout << (1 << count) - 1 << std::endl;
        }

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        tmp.push_back(duration.count());
    }

    for (auto &vec : tmp) {
        std::cout << vec << "ms" << std::endl;
    }

    return 0;
}
