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
    int findMaximumLength(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int64_t> psum(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        
        std::vector<int> dp(n + 1, 0);
        std::vector<int64_t> last(n + 1, 0);
        std::vector<int> s;
        
        auto cmp = [&](int64_t x, int y) {
            return x < psum[y] + last[y];
        };
        
        s.push_back(0);
        for(int i = 1; i <= n; i++) {
            auto it = std::upper_bound(s.begin(), s.end(), psum[i], cmp);
            it--;
            dp[i] = dp[*it] + 1;
            last[i] = psum[i] - psum[*it];
            
            while(!s.empty() && psum[i] + last[i] <= psum[s.back()] + last[s.back()]) {
                s.pop_back();
            }
            
            s.push_back(i);
        }
        
        return dp[n];
    }
};
