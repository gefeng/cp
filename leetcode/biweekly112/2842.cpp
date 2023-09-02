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

    int countKSubsequencesWithMaxBeauty(std::string s, int k) {
        if(k > 26) {
            return 0;
        }
        
        int64_t ans = 1;
        int n = s.size();
        int max_b = 0;
        int min_f = 0;
        std::vector<int> cnt(26, 0);
        std::vector<int64_t> fact(n + 1, 1);
        std::vector<int64_t> invf(n + 1, 1);
        
        for(char c : s) {
            cnt[c - 'a'] += 1;
        }
        
        for(int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        
        for(int i = 2; i <= n; i++) {
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        std::sort(cnt.begin(), cnt.end(), std::greater<int>());
        
        for(int i = 0; i < k; ) {
            if(cnt[i] == 0) {
                return 0;
            }
            
            int j = i;
            while(i < 26 && cnt[i] == cnt[j]) {
                i += 1;
            }
            
            int have = i - j;
            int take = std::min(have, k - j);
            
            int64_t x = (fact[have] * invf[take] % MOD) * invf[have - take] % MOD;
            int64_t y = 1;
            for(int k = 0; k < take; k++) {
                y *= cnt[j];
                y %= MOD;
            }
            
            ans *= x * y % MOD;
            ans %= MOD;
        }
        
        return ans;
    }
};
