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
    int maximumLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, -1));
        dp[0][0] = 1;
        
        for(int i = 1; i < n; i++) {
            std::vector<std::vector<int>> ndp(k + 1, std::vector<int>(n + 1, -1));
            ndp[0][i] = 1;
            
            for(int j = 0; j <= k; j++) {
                for(int l = 0; l < i; l++) {
                    if(nums[i] != nums[l]) {
                        if(j - 1 >= 0 && dp[j - 1][l] != -1) {
                            ndp[j][i] = std::max(ndp[j][i], dp[j - 1][l] + 1);
                        }
                    } else {
                        if(dp[j][l] != -1) {
                            ndp[j][i] = std::max(ndp[j][i], dp[j][l] + 1);
                        }
                    }
                    
                    ndp[j][l] = std::max(ndp[j][l], dp[j][l]);
                }
            }
            
            std::swap(dp, ndp);
        }
        
        int ans = 0;
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j < n; j++) {
                ans = std::max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
