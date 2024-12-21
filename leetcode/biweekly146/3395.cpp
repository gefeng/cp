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
    
    int subsequencesWithMiddleMode(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::vector<int64_t> fact(n + 1, 1);
        std::vector<int64_t> invf(n + 1, 1);
        std::map<int, int> m_1;
        std::map<int, int> m_2;
        
        for(int i = 0; i < n; i++) {
            m_1[nums[i]] += 1;
        }
        
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invf[i] = q_pow(fact[i], MOD - 2);
        }
        
        for(int i = 0; i < 2; i++) {
            m_2[nums[i]] += 1;
        }
        
        for(int i = 2; i < n - 2; i++) {
            int l = i;
            int r = n - i - 1;
            int64_t tot = ((fact[l] * invf[2] % MOD) * invf[l - 2] % MOD) * ((fact[r] * invf[2] % MOD) * invf[r - 2] % MOD);
            tot %= MOD;
            
            int f_l = m_2[nums[i]];
            int f_r = m_1[nums[i]] - 1 - f_l;
            
            int f = f_l;
            int64_t a = 0;
            int64_t b = 0;
            
            if(l - f >= 2) {
                a = (fact[l - f] * invf[2] % MOD) * invf[l - f - 2] % MOD;
            }
            f = m_1[nums[i]] - 1 - f;
            if(r - f >= 2) {
                b = (fact[r - f] * invf[2] % MOD) * invf[r - f - 2] % MOD;
            }
            tot -= a * b % MOD;
            tot += MOD;
            tot %= MOD;
            
            f = f_l;
            if(f > 0) {
                for(auto [v, x] : m_2) {
                    if(v == nums[i]) {
                        continue;
                    }
                    int y = m_1[v] - x;
                    if(y > 0) {
                        int64_t cnt = (int64_t(f) * x % MOD) * y % MOD;
                        cnt = cnt * (r - 1 - f_r) % MOD;
                        tot -= cnt;
                        tot += MOD;
                        tot %= MOD;
                    }
                    if(y > 1) {
                        tot += (int64_t(f) * x % MOD) * ((fact[y] * invf[2] % MOD) * invf[y - 2] % MOD) % MOD;
                        tot %= MOD;
                    }
                }
            }
            
            f = f_r;
            if(f > 0) {
                for(auto [v, x] : m_2) {
                    if(v == nums[i]) {
                        continue;
                    }
                    int y = m_1[v] - x;
                    if(y > 0) {
                        int64_t cnt = (int64_t(f) * x % MOD) * y % MOD;
                        cnt = cnt * (l - 1 - f_l) % MOD;
                        tot -= cnt;
                        tot += MOD;
                        tot %= MOD;
                    }
                    if(x > 1) {
                        tot += (int64_t(f) * y % MOD) * ((fact[x] * invf[2] % MOD) * invf[x - 2] % MOD) % MOD;
                        tot %= MOD;
                    }
                }
            }
            
            for(auto [v, x] : m_1) {
                if(v == nums[i]) {
                    continue;
                }

                int cnt_l = m_2.find(v) == m_2.end() ? 0 : m_2[v];
                int cnt_r = x - cnt_l;
                if(cnt_r > 1 && f_l > 0) {
                    tot -= ((((fact[cnt_r] * invf[2] % MOD) * invf[cnt_r - 2] % MOD) % MOD) * f_l % MOD) * (l - f_l - cnt_l) % MOD;
                    tot += MOD;
                    tot %= MOD;
                }
                if(cnt_l > 1 && f_r > 0) {
                    tot -= ((((fact[cnt_l] * invf[2] % MOD) * invf[cnt_l - 2] % MOD) % MOD) * f_r % MOD) * (r - f_r - cnt_r) % MOD;
                    tot += MOD;
                    tot %= MOD;
                }
            }
            
            m_2[nums[i]] += 1;
            ans += tot;
            ans %= MOD;
        }
        
        return ans;
    }
};
