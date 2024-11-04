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
    const int64_t MOD = int64_t(1e9) + 7;
    
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
    
    int countBalancedPermutations(std::string num) {
        int n = num.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += num[i] - '0';
        }
        
        if(sum % 2 == 1) {
            return 0;
        }
        
        std::array<int, 10> freq = {};
        for(int i = 0; i < n; i++) {
            freq[num[i] - '0'] += 1;
        }
        
        std::vector<std::vector<int64_t>> fact(n + 1, std::vector<int64_t>(n + 1, 1));
        std::vector<int64_t> invf(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            fact[i][i] = i;
            for(int j = i + 1; j <= n; j++) {
                fact[i][j] = fact[i][j - 1] * j % MOD;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            invf[i] = q_pow(fact[1][i], MOD - 2);
        }
        
        int m = n / 2;
        int t = sum / 2;
        std::vector<std::vector<int64_t>> dp(m + 1, std::vector<int64_t>(t + 1, 0));
        dp[0][0] = 1;
        
        int p = 0;
        for(int i = 0; i < 10; i++) {
            std::vector<std::vector<int64_t>> ndp(m + 1, std::vector<int64_t>(t + 1, 0));
            int c = freq[i];
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= t; k++) {
                    if(c == 0) {
                        ndp[j][k] = dp[j][k];
                    } else {
                        for(int s = 0; s <= c; s++) {
                            if(j - s >= 0 && k - s * i >= 0 && j - s <= p) {
                                int64_t x = fact[j - s + 1][j] * invf[s] % MOD;
                                int64_t y = fact[p - j + s + 1][p - j + c] * invf[c - s] % MOD;
                                ndp[j][k] += dp[j - s][k - s * i] * (x * y % MOD) % MOD;
                                ndp[j][k] %= MOD;
                            }
                        }
                    }
                }
            }
            std::swap(dp, ndp);
            p += freq[i];
        }
        
        return dp[m][t];
    }
};
