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
    
    int distanceSum(int m, int n, int k) {
        int64_t ans = 0;
        int64_t sum = 0;
        
        sum = int64_t(0 + m - 1) * m / 2;
        sum %= MOD;
        ans = sum;
        
        for(int i = 1; i < n; i++) {
            sum += m;
            sum %= MOD;
            ans += sum;
        }
        
        sum = ans;
        for(int i = 1; i < m * n; i++) {
            int r = i / m;
            int c = i % m;
            
            sum -= int64_t(m) * n - i;
            sum += MOD;
            sum %= MOD;
            
            if(r + 1 < n && c - 1 >= 0) {
                sum += int64_t(n - 1 - r) * c * 2;
                sum %= MOD;
            }
            
            ans += sum;
            ans %= MOD;
        }
        
        std::vector<int64_t> fact(m * n + 1, 1);
        std::vector<int64_t> invf(m * n + 1, 1);
        for(int i = 1; i <= m * n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        ans *= (fact[m * n - 2] * invf[k - 2] % MOD) * invf[m * n - k] % MOD;
        ans %= MOD;
        
        return ans;
    }
};
