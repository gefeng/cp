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
    std::vector<int> minCosts(std::vector<int>& cost) {
        int n = cost.size();
        std::vector<int> ans(n, 0);
        
        int min_v = int(1e9);
        for(int i = 0; i < n; i++) {
            ans[i] = std::min(min_v, cost[i]);
            min_v = std::min(min_v, cost[i]);
        }
        
        return ans;
    }
};
