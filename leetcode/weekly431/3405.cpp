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
    
    int countGoodArrays(int n, int m, int k) {
        int64_t ans = 0;
        
        if(n == 1) {
            return m;
        }
        
        if(m == 1) {
            return k != n - 1 ? 0 : 1;
        }
        
        
        std::vector<int64_t> fact(n + 1, 1);
        std::vector<int64_t> invf(n + 1, 1);
        
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        int64_t pm = 1;
        for(int i = 0; i < n - k - 1; i++) {
            pm *= (m - 1);
            pm %= MOD;
        }
        
        ans = (fact[n - 1] * invf[n - 1 - k] % MOD) * invf[k] % MOD;
        ans *= m * pm % MOD;
        ans %= MOD;
        
        return ans;
    }
};
