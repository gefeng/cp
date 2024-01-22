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
    const int64_t MAX = (int64_t)1e16;
    
    // from gfg
    int64_t getSetBitsFromOneToN(int64_t N, int mod) {
        int64_t two = 2, ans = 0;
        int64_t n = N;
        int64_t b = 1;
        while (n) {
            if(b % mod == 0) {
                ans += (N / two) * (two >> 1);
            }
            if ((N & (two - 1)) > (two >> 1) - 1 && b % mod == 0) {
                ans += (N & (two - 1)) - (two >> 1) + 1;
            }
            two <<= 1;
            n >>= 1;
            b += 1;
        }
        return ans;
    }
    long long findMaximumNumber(long long k, int x) {
        int64_t lo = 1;
        int64_t hi = MAX;
        int64_t ans = 0;
        while(lo <= hi) {
            int64_t mid = (lo + hi) >> 1;
            int64_t score = getSetBitsFromOneToN(mid, x);
            
            if(score <= k) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
