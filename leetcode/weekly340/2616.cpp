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
    int minimizeMax(std::vector<int>& nums, int p) {
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        int lo = 0;
        int hi = (int)1e9;
        int ans = (int)1e9;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            std::vector<int> dp(n + 1, 0);
            for(int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1];
                if(nums[i - 1] - nums[i - 2] <= mid) {
                    dp[i] = std::max(dp[i], dp[i - 2] + 1);
                }
            }
            
            if(dp[n] >= p) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
