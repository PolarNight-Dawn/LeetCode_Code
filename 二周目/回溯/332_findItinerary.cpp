#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

//
// Created by polarnight on 23-10-12, 下午2:38.
//

// class Solution {
// public:
//     std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
//         // 两个机场间可能有多张机票，所以value用int来计数
//         // map保证value有序，可以保证第一个搜索结果即为最终结果
//         std::map<std::string, std::map<std::string, int>> m, vis;
//         for(auto t: tickets) m[t[0]][t[1]]++;
//         std::vector<std::string> res, cur;
//         // 添加起始点
//         cur.push_back("JFK");
//         dfs(m, vis, cur, tickets.size()+1, res);
//         return res;
//     }
//     void dfs(std::map<std::string, std::map<std::string, int>>& m, std::map<std::string, std::map<std::string, int>>& vis, std::vector<std::string>& cur, int n, std::vector<std::string>& res) {
//         // 如果已经找到一个结果，直接返回
//         if(res.size()==n) return;
//         if(cur.size()==n) {
//             res = cur;
//             return;
//         }
//         // 没有以当前机场为起点的机票，中止搜索
//         if(m.find(cur.back())==m.end()) return;
//         // 遍历
//         for(auto it: m[cur.back()]) {
//             std::string stop = it.first;
//             // 根据机票数量判断是否可以继续搜索
//             if(vis[cur.back()][stop]==it.second) continue;
//             vis[cur.back()][stop]++;
//             cur.push_back(stop);
//             dfs(m, vis, cur, n, res);
//             cur.pop_back();
//             vis[cur.back()][stop]--;
//             // 如果已经找到一个结果，直接返回
//             if(res.size()==n) return;
//         }
//     }
// };

class Solution {
private:
// unordered_map<出发城市, map<到达城市, 航班次数>> targets
    std::unordered_map<std::string, std::map<std::string, int>> targets;
    bool backtracking(int ticketNum, std::vector<std::string>& result) {
        if (result.size() == ticketNum + 1) {
            return true;
        }
        for (std::pair<const std::string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0 ) { // 使用int字段来记录到达城市是否使用过了
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::vector<std::string> result;
        for (const auto &vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录映射关系
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};

int main332() {
    std::vector<std::vector<std::string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    Solution sol;
    std::vector<std::string> res = sol.findItinerary(tickets);

    // 在默认情况下,C++的标准输出是行缓冲的(line buffered)
    // 这意味着输出stream不会立即输出,而是等待一个换行字符才会flush。
    std::cout << "Itinerary:" << std::endl;
    for (auto& s : res) {
        std::cout << s << " -> ";
    }
    std::cout << "END" << std::endl;
    // for (int i = 0; i < res.size(); i++) {
    //     std::cout << std::unitbuf << res[i] << " "; // 无缓冲模式
    // }
    // std::cout << std::flush; // 强制刷新输出

    return 0;
}
