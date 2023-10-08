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
    int maxSum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> cnt(30, 0);
        
        for(int x : nums) {
            for(int i = 0; i < 30; i++) {
                if(x & (1 << i)) {
                    cnt[i] += 1; 
                }
            }
        }
        
        std::vector<int64_t> a(k, 0);
        for(int i = 29; i >= 0; i--) {
            for(int j = 0; j < k; j++) {
                if(cnt[i]) {
                    a[j] |= 1 << i;
                    cnt[i] -= 1;
                }
            }
        }
        
        int64_t ans = 0;
        for(int64_t x : a) {
            ans += x * x % MOD;
            ans %= MOD;
        }
        
        return ans;
    }
};
