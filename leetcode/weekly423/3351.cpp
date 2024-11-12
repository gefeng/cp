#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;
constexpr int MAX = int(1e5);

class Solution {
public:
    int sumOfGoodSubsequences(std::vector<int>& nums) {
        int n = nums.size();
        
        std::vector<int64_t> dp(MAX + 1, 0);
        std::vector<int64_t> ds(MAX + 1, 0);
        
        for(int i = 0; i < n; i++) {
            int64_t sum = nums[i];
            int64_t cnt = 1;
            if(nums[i] - 1 >= 0) {
                cnt += dp[nums[i] - 1];
                cnt %= MOD;
                
                sum += ds[nums[i] - 1] + (dp[nums[i] - 1] * nums[i] % MOD);
                sum %= MOD;
            }
            if(nums[i] + 1 <= MAX) {
                cnt += dp[nums[i] + 1];
                cnt %= MOD;
                
                sum += ds[nums[i] + 1] + (dp[nums[i] + 1] * nums[i] % MOD);
                sum %= MOD;
            }
            
            dp[nums[i]] += cnt;
            dp[nums[i]] %= MOD;
            ds[nums[i]] += sum;
            ds[nums[i]] %= MOD;
        }
        
        int64_t ans = 0;
        for(int i = 0; i <= MAX; i++) {
            ans += ds[i];
            ans %= MOD;
        }
        
        return ans;
    }
};
