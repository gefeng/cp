#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    LL q_pow(LL x, LL y) {
        LL res = 1LL;
        while(y) {
            if(y & 1) {
                res *= x;
                res %= MOD;
            } 
            x *= x;
            x %= MOD;
            y >>= 1LL;
        }
        return res;
    }
    
    int countAnagrams(string s) {
        int n = s.length();
        
        vector<LL> fact(n + 1, 0LL);
        vector<LL> invf(n + 1, 0LL);
        fact[0] = 1LL;
        invf[0] = 1LL;
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        for(int i = 1; i <= n; i++) {
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        LL ans = 1LL;
        string w = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                w.push_back(s[i]);
            }
            if(s[i] == ' ' || i == n - 1) {
                array<int, 26> cnt{0};
                for(char c : w) {
                    cnt[c - 'a'] += 1;
                }
                
                int x = w.length();
                LL tot = fact[x];
                
                for(int j = 0; j < 26; j++) {
                    if(cnt[j]) {
                        tot *= invf[cnt[j]];
                        tot %= MOD;
                    }
                }
                
                ans *= tot;
                ans %= MOD;
                w = "";
            } 
        }
        
        return ans;
    }
};
