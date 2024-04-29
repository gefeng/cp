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
    long long minEnd(int n, int x) {
        int64_t y = n - 1;
        int64_t ans = x;
        for(int i = 0, j = 0; i < 30; j++) {
            if(x & (int64_t(1) << j)) {
                continue;
            }
            
            if(y & (1 << i)) {
                ans |= int64_t(1) << j;
            }
            i += 1;
        }
        
        return ans;
    }
};
