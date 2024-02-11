#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr std::array<int64_t, 2> BASE = {23, 31};
constexpr std::array<int64_t, 2> MOD = {998244353, (int64_t)1e9 + 7};

class Solution {
public:
    int countMatchingSubarrays(std::vector<int>& nums, std::vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        
        std::vector<int> a(n - 1);
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                a[i - 1] = 1;
            } else if(nums[i] == nums[i - 1]) {
                a[i - 1] = 0;
            } else {
                a[i - 1] = -1;
            }
        }
        
        std::array<int64_t, 2> t = {};
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < m; j++) {
                t[i] = (t[i] * BASE[i] % MOD[i]) + (pattern[j] + 2);
                t[i] %= MOD[i];
            }    
        }
        
        int64_t h1 = 0;
        int64_t h2 = 0;
        int64_t d1 = 1;
        int64_t d2 = 1;
        int64_t ans = 0;
        for(int l = 0, r = 0; r < n - 1; r++) {
            h1 = (h1 * BASE[0] % MOD[0]) + (a[r] + 2);
            h2 = (h2 * BASE[1] % MOD[1]) + (a[r] + 2);
            if(r - l + 1 <= m) {
                d1 *= BASE[0];
                d2 *= BASE[1];
                d1 %= MOD[0];
                d2 %= MOD[1];
            }
            
            if(r - l + 1 > m) {
                h1 -= (d1 * (a[l] + 2) % MOD[0]);
                h1 += MOD[0];
                h1 %= MOD[0];
                
                h2 -= (d2 * (a[l] + 2) % MOD[1]);
                h2 += MOD[1];
                h2 %= MOD[1];
                
                l += 1;
            }
            
            if(r - l + 1 == m) {
                if(h1 == t[0] && h2 == t[1]) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
