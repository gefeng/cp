#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

class Solution {
public:
    int minArraySum(std::vector<int>& nums, int a, int op1, int op2) {
        int n = nums.size();
        std::vector<std::vector<int>> dp(op1 + 1, std::vector<int>(op2 + 1, INF));
        
        dp[0][0] = 0;
        
        for(int i = 0; i < n; i++) {
            std::vector<std::vector<int>> ndp(op1 + 1, std::vector<int>(op2 + 1, INF));
            
            for(int j = 0; j <= op1; j++) {
                for(int k = 0; k <= op2; k++) {
                    if(dp[j][k] != INF) {
                        ndp[j][k] = std::min(ndp[j][k], dp[j][k] + nums[i]);
                        if(j + 1 <= op1) {
                            ndp[j + 1][k] = std::min(ndp[j + 1][k], dp[j][k] + (nums[i] + 1) / 2);
                        }
                        if(k + 1 <= op2 && nums[i] >= a) {
                            ndp[j][k + 1] = std::min(ndp[j][k + 1], dp[j][k] + nums[i] - a);
                        }
                        if(j + 1 <= op1 && k + 1 <= op2) {
                            int x = (nums[i] + 1) / 2;
                            if(x >= a) {
                                ndp[j + 1][k + 1] = std::min(ndp[j + 1][k + 1], dp[j][k] + x - a);
                            }
                            
                            if(nums[i] >= a) {
                                x = (nums[i] - a + 1) / 2;
                                ndp[j + 1][k + 1] = std::min(ndp[j + 1][k + 1], dp[j][k] + x);
                            }
                         }
                    }
                }
            }
            
            std::swap(dp, ndp);
        }
        
        int ans = INF;
        for(int i = 0; i <= op1; i++) {
            for(int j = 0; j <= op2; j++) {
                ans = std::min(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
