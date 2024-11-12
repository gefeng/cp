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
    
    int countKReducibleNumbers(std::string s, int k) {
        if(s == "1") {
            return 0;
        }
        
        int n = s.size();
        std::vector<int64_t> fact(n + 1, 1);
        std::vector<int64_t> invf(n + 1, 1);
        std::vector<int64_t> cnt_less(n + 1, 0);
                
        auto is_good = [&](int len) {
            int res = 1;
            int x = len;
            while(x != 1) {
                x = __builtin_popcount(x);
                res += 1;
            }
            return res <= k;
        };
        
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        int cnt_one = 0;
        for(int i = 0; i < n; i++) {
            cnt_one += s[i] - '0';
        }
        
        int prefix = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                continue;
            }
            
            for(int j = 0; j <= n - i - 1; j++) {
                int64_t x = (fact[n - i - 1] * invf[j] % MOD) * invf[n - i - 1 - j] % MOD;
                cnt_less[j + prefix] += x;
                cnt_less[j + prefix] %= MOD;
            }
            
            prefix += 1;
        }
        
        int64_t ans = 0;
        for(int i = 1; i <= n; i++) {
            if(is_good(i)) {
                ans += cnt_less[i];
                ans %= MOD;
            } else {
                if(i == 1) {
                    ans += 1;
                    ans %= MOD;
                }
            }
        }
        
        return ans;
    }
};
