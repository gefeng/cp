#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

class Solution {
public:
    long long minimumCost(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        auto is_pal = [](int x) {
            std::vector<int> d;
            while(x) {
                d.push_back(x % 10);
                x /= 10;
            }
            for(int l = 0, r = d.size() - 1; l < r; l++, r--) {
                if(d[l] != d[r]) {
                    return false;
                }
            }
            return true;
        };
        
        auto get_cost = [&](int x) {
            int64_t cost = 0;
            for(int y : nums) {
                cost += std::abs(x - y);
            }
            return cost;
        };
        
        int64_t ans = INF;
        int cur = nums[nums.size() / 2];
        while(!is_pal(cur)) {
            cur += 1;
        }
        
        ans = std::min(ans, get_cost(cur));
        
        cur = nums[nums.size() / 2];
        while(!is_pal(cur)) {
            cur -= 1;
        }
        
        ans = std::min(ans, get_cost(cur));
        
        return ans;
    }
};
