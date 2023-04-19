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
    int miceAndCheese(std::vector<int>& reward1, std::vector<int>& reward2, int k) {
        int n = reward1.size();
        
        std::vector<std::pair<int, int>> r(n);
        
        for(int i = 0; i < n; i++) {
            r[i].first = reward1[i];
            r[i].second = reward2[i];
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a.first - a.second > b.first - b.second;
        };
        
        std::sort(r.begin(), r.end(), cmp);
        
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += r[i].first;
        }
        
        for(int i = k; i < n; i++) {
            ans += r[i].second;
        }
        
        return ans;
    }
};
