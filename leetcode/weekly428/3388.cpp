#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

struct rolling_hash {
    const int64_t MOD = int64_t(1e9) + 7;
    const int64_t BASE = 91;
    
    std::vector<int64_t> h;
    std::vector<int64_t> d;
    
    rolling_hash(std::vector<int>& a) {
        int n = a.size();
        h.resize(n + 1, 0);
        d.resize(n + 1, 1);
        
        for(int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * BASE % MOD + a[i] + 1) % MOD;
            d[i + 1] = d[i] * BASE % MOD;
        }
    }
    
    int64_t query(int l, int r) {
        int64_t res = h[r + 1];
        res -= h[l] * d[r - l + 1] % MOD;
        res += MOD;
        res %= MOD;
        return res;
    }
};

class Solution {
public:
    int beautifulSplits(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        rolling_hash h(nums);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int len = i + 1;
                int64_t h_1 = h.query(0, i);
                if(j + len - 1 < n) {
                    int64_t h_2 = h.query(i + 1, j + len - 1);
                    if(h_1 == h_2) {
                        ans += n - j - len;
                    }
                }
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = j - i + 1;
                if(n - 1 - j >= len) {
                    int64_t h_1 = h.query(i, j);
                    int64_t h_2 = h.query(j + 1, j + len);
                    if(h_1 == h_2) {
                        ans += 1;
                    }
                }
            }
        }
              
        for(int i = 1; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = j - i + 1;
                if(i <= len && n - 1 - j >= len) {
                    int64_t h_1 = h.query(0, i - 1);
                    int64_t h_2 = h.query(i, i + i - 1);
                    int64_t h_3 = h.query(i, j);
                    int64_t h_4 = h.query(j + 1, j + len);
                    if(h_1 == h_2 && h_3 == h_4) {
                        ans -= 1;
                    }
                }
            }
        }
        
        return ans;
    }
};
