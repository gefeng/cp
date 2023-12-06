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
    
    int numberOfSequence(int n, std::vector<int>& sick) {
        int64_t ans = 1;
        
        std::vector<int64_t> fact(n + 1, 1);
        std::vector<int64_t> p2(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            p2[i] = p2[i - 1] * 2 % MOD;
            fact[i] = fact[i - 1] * i % MOD;
        }
    
        ans = fact[n - sick.size()];
        int pre = -1;
        for(auto s : sick) {
            if(pre != -1 && s - pre > 1) {
                ans *= p2[s - pre - 2];
                ans %= MOD;
            } 
            if(s - pre > 1) {
                ans *= q_pow(fact[s - pre - 1], MOD - 2);
                ans %= MOD;
            }
            pre = s;
        }
        
        if(sick.back() != n - 1) {
            ans *= q_pow(fact[n - sick.back() - 1], MOD - 2);
            ans %= MOD;
        }
        
        return ans;
    }
};
