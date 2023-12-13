#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

//
// Created by polarnight on 23-11-22, 下午2:35.
//

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        std::unordered_set<int> visited;
        std::unordered_set<int> haved;
        std::queue<int> keys;

        for (int i : rooms[0]) {
            keys.push(i);
            haved.insert(i);
        }

        while (!keys.empty()) {
            int key = keys.front();
            keys.pop();
            for (int i : rooms[key]) {
                if (haved.count(i) == 0 && i != 0) {
                    keys.push(i);
                    haved.insert(i);
                }
            }
            visited.insert(key);
        }
        return visited.size() == rooms.size() - 1;
    }
};

int main841() {
    std::vector<std::vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {}};

    Solution sol;
    std::cout << sol.canVisitAllRooms(rooms);

    return 0;
}