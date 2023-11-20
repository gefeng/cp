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
    int maximumXorProduct(long long a, long long b, int n) {
        for(int i = n - 1; i >= 0; i--) {
            if((a & (1LL << i)) == 0 && (b & (1LL << i)) == 0) {
                a |= (1LL << i);
                b |= (1LL << i);
            } else if((a & (1LL << i)) != (b & (1LL << i))) {
                if(a < b) {
                    if((a & (1LL << i)) == 0) {
                        a ^= 1LL << i;
                        b ^= 1LL << i;
                    } 
                } else {
                    if((b & (1LL << i)) == 0) {
                        a ^= 1LL << i;
                        b ^= 1LL << i;
                    }
                }
            }
        }
        
        return (a % MOD) * (b % MOD) % MOD;
    }
};
