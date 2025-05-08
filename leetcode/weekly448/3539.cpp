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

class Solution {
public:
    std::vector<int64_t> fact;
    std::vector<int64_t> invf;

    int64_t q_pow(int64_t x, int64_t y) {
        int64_t res = 1;
        while(y) {
            if(y & 1) {
                res *= x;
                res %= MOD;
            }
            x *= x;
            x %= MOD;
            y >>= 1;
        }
        return res;
    }
    
    int64_t dfs(std::vector<int>& nums, int m, int k, int c, int now, 
                std::vector<std::vector<std::vector<std::vector<int64_t>>>>& dp) {
        if(now == nums.size()) {
            while(c) {
                k -= c % 2;
                c /= 2;
            }
            return m == 0 && k == 0 ? 1 : 0;
        }
        
        if(dp[m][k][c][now] != -1) {
            return dp[m][k][c][now];
        }
        
        int64_t res = 0;
        
        if(k - c % 2 >= 0) {
            res += dfs(nums, m, k - c % 2, c / 2, now + 1, dp);
            res %= MOD;
        } 
        
        int bit = c;
        int64_t prod = 1;
        for(int i = 1; i <= m; i++) {
            bit += 1;
            if(k - bit % 2 >= 0) {
                int64_t x = dfs(nums, m - i, k - bit % 2, bit / 2, now + 1, dp);
                prod *= nums[now];
                prod %= MOD;
            
                res += (x * prod % MOD) * invf[i] % MOD;
                res %= MOD;
            }
        }
        
        return dp[m][k][c][now] = res;
    }
    
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        
        fact.resize(51, 1);
        invf.resize(51, 1);
        for(int i = 1; i <= 50; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        std::vector<std::vector<std::vector<std::vector<int64_t>>>> dp(m + 1, std::vector<std::vector<std::vector<int64_t>>>(k + 1, std::vector<std::vector<int64_t>>(m + 1, std::vector<int64_t>(n, -1))));
        
        int64_t ans = dfs(nums, m, k, 0, 0, dp);
        ans *= fact[m];
        ans %= MOD;
        
        return ans;
    }
};
