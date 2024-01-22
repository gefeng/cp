#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;
constexpr int64_t BASE = 31;

class Solution {
public:
    std::vector<int> beautifulIndices(std::string s, std::string a, std::string b, int k) {
        auto hashify = [&](std::string& t) {
            int n = t.size();
            int64_t h = 0;
            for(int i = 0; i < n; i++) {
                h = h * BASE % MOD + t[i] - 'a' + 1;
                h %= MOD;
            }
            return h;
        };
        
        int64_t ha = hashify(a);
        int64_t hb = hashify(b);
        
        int n = s.size();
        std::vector<int64_t> pow(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            pow[i] = pow[i - 1] * BASE % MOD;
        }
        
        int m = b.size();
        int64_t h = 0;
        std::vector<int> good;
        std::vector<int64_t> save(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            h = h * BASE % MOD + s[i - 1] - 'a' + 1;
            h %= MOD;
            save[i] = h;
            if(i >= m) {
                int64_t pre = (save[i - m] * pow[m] % MOD);
                int64_t x = (h - pre + MOD) % MOD;
                if(x == hb) {
                    good.push_back(i - m);
                }
            }
        }
        
        m = a.size();
        std::vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(i >= m) {
                int64_t pre = (save[i - m] * pow[m] % MOD);
                int64_t x = (save[i] - pre + MOD) % MOD;
                if(x == ha) {
                    bool dist = false;
                    int j = i - m;
                    auto it = std::upper_bound(good.begin(), good.end(), j);
                    if(it != good.end()) {
                        if(std::abs(*it - j) <= k) {
                            dist = true;
                        }
                    }
                    if(it != good.begin()) {
                        it--;
                        if(std::abs(*it - j) <= k) {
                            dist = true;
                        }
                    }

                    if(dist) {
                        ans.push_back(j);
                    }
                }
            }    
        }
        
        return ans;
    }
};
