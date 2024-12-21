#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
        int m = rectangles.size();
        
        std::vector<std::pair<int, int>> e_1;
        std::vector<std::pair<int, int>> e_2;
        
        for(int i = 0; i < m; i++) {
            std::vector<int>& r = rectangles[i];
            e_1.emplace_back(r[0], 0);
            e_1.emplace_back(r[2], 1);
            e_2.emplace_back(r[1], 0);
            e_2.emplace_back(r[3], 1);
        }
        
        auto solve = [](std::vector<std::pair<int, int>>& events) {
            int n = events.size();
            std::sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
                if(a.first == b.first) {
                    return a.second > b.second;
                }
                return a.first < b.first;
            });
            
            int res = 0;
            int sum = 0;
            for(int i = 0; i < n; ) {
                int j = i;
                while(i < n && events[i].first == events[j].first) {
                    i += 1;
                }
                
                for(int k = j; k < i; k++) {
                    auto [x, t] = events[k];
                    if(t == 0) {
                        sum += 1;
                    } else {
                        sum -= 1;
                    }
                    if(sum == 0 && k != n - 1) {
                        res += 1;
                    }
                }
            }
            return res;
        };
        
        return solve(e_1) >= 2 || solve(e_2) >= 2;
    }
};
