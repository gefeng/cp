#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int64_t gcd(int64_t a, int64_t b) {
        if(a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    
    int64_t lcm(int64_t a, int64_t b) {
        return a * b / gcd(a, b);
    }
    
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        int64_t lo = 1;
        int64_t hi = (int64_t)1e18;
        int64_t ans = 0;
        while(lo <= hi) {
            int64_t mid = (lo + hi) >> 1;
            
            int64_t cnt = 0;
            for(int i = 1; i < (1 << n); i++) {
                int64_t x = 0;
                int p = 0;
                for(int j = 0; j < n; j++) {
                    if(i & (1 << j)) {
                        x = x == 0 ? coins[j] : lcm(x, coins[j]);
                        p ^= 1;
                    }
                }
                
                if(p) {
                    cnt += mid / x;
                } else {
                    cnt -= mid / x;
                }
            }
            
            if(cnt >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
