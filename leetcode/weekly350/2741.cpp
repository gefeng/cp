#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int specialPerm(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<LL>> dp(n, std::vector<LL>(1 << n, 0LL));
        
        for(int i = 0; i < n; i++) {
            dp[i][1 << i] = 1LL;
        }
        
        auto is_good = [](int a, int b) {
            return a % b == 0 || b % a == 0;
        };
        
        for(int i = 0; i < (1 << n); i++) {
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    for(int k = 0; k < n; k++) {
                        if((i & (1 << k)) == 0 && is_good(nums[k], nums[j])) {
                            dp[k][i | (1 << k)] += dp[j][i];
                            dp[k][i | (1 << k)] %= MOD;
                        }
                    }
                }
            }
        }
        
        LL ans = 0LL;
        for(int i = 0; i < n; i++) {
            ans += dp[i][(1 << n) - 1];
            ans %= MOD;
        }
        
        return ans;
    }
};
