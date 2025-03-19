#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = 1000;

class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int ans = -1;
        
        auto solve = [&](int x, int p) {
            std::vector<int> dp(MAX + 1, 0);
            dp[x] = 1;
            
            for(int i = 0; i < m; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int d = queries[i][2];
                std::vector<int> ndp(dp);
                
                if(p >= l && p <= r) {
                    for(int j = 0; j <= MAX; j++) {
                        if(j - d >= 0) {
                            ndp[j - d] |= dp[j];
                        }
                    }
                }
                
                std::swap(dp, ndp);
                if(dp[0]) {
                    return i + 1;
                }
            }
            
            return -1;
        };
        
        for(int i = 0; i < n; i++) { 
            if(nums[i] == 0) {
                ans = std::max(ans, 0);
                continue;
            }
            
            int j = solve(nums[i], i);
            if(j == -1) {
                return -1;
            }
            ans = std::max(ans, j);
        }
        
        return ans;
    }
};
