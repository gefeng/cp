#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int64_t dfs(std::vector<int>& nums, int k, int p, int i, int last, int len, std::vector<std::vector<std::vector<int>>>& dp) {
        int n = nums.size();
        if(len == k) {
            return 1;
        }
        if(i == n) {
            return 0;
        }
        
        if(dp[i][last][len] != -1) {
            return dp[i][last][len];
        }
        
        int64_t res = 0;
        if(last == n) {
            for(int j = 0; j < n; j++) {
                res += dfs(nums, k, p, j, j, 1, dp);
                res %= MOD;
            }
        } else {
            res += dfs(nums, k, p, i + 1, last, len, dp);
            res %= MOD;
        
            if(nums[i] - nums[last] >= p) {
                res += dfs(nums, k, p, i + 1, i, len + 1, dp);
                res %= MOD;
            }
        }
        
        return dp[i][last][len] = res;
    }
    
    int sumOfPowers(std::vector<int>& nums, int k) {
        int n = nums.size();
    
        std::sort(nums.begin(), nums.end());
        
        std::set<int> s;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                s.insert(nums[j] - nums[i]);
            }
        }
        
        int64_t ans = 0;
        int64_t pre = -1;
        std::vector<std::pair<int, int>> save;
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n + 1, std::vector<int>(k + 1, -1)));
        for(int p : s) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= n; j++) {
                    for(int l = 0; l <= k; l++) {
                        dp[i][j][l] = -1;
                    }
                }
            }
            int64_t cnt = dfs(nums, k, p, 0, n, 0, dp);
            save.emplace_back(p, cnt);
        }
        
        int size = save.size();
        for(int i = size - 1; i >= 0; i--) {
            ans += i == size - 1 ? (int64_t)save[i].first * save[i].second % MOD : (int64_t)save[i].first * ((save[i].second - save[i + 1].second + MOD) % MOD) % MOD;
            ans %= MOD;
        }
        
        return ans;
    }
};
