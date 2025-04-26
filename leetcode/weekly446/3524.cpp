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
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long long> ans(k, 0);
        
        std::vector<std::vector<int64_t>> dp(k, std::vector<int64_t>(n, 0));
        
        for(int i = 0; i < n; i++) {
            dp[nums[i] % k][i] += 1;
            if(i) {
                for(int j = 0; j < k; j++) {
                    int rem = j * (nums[i] % k) % k;
                    dp[rem][i] += dp[j][i - 1];
                }    
            }
        }
        
        for(int x = 0; x < k; x++) {
            for(int i = 0; i < n; i++) {
                ans[x] += dp[x][i];
            }    
        }
        
        return ans;
    }
};
