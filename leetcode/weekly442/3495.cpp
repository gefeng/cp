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
    long long minOperations(std::vector<std::vector<int>>& queries) {
        int n = queries.size();
        int64_t ans = 0;
        
        for(int i = 0; i < n; i++) {
            int64_t l = queries[i][0];
            int64_t r = queries[i][1];
            int64_t cnt = 0;
            int64_t p_2 = 1;
            int64_t now = l;
            
            for(int k = 1; k <= 30 && now <= r; k++) {
                p_2 *= 2;
                if(p_2 <= now) {
                    continue;
                }
                
                int64_t nxt = std::min(p_2 - 1, r);
                cnt += (k + 1) / 2 * (nxt - now + 1);
                now = nxt + 1;
            }
            ans += (cnt + 1) / 2;
        }
        
        return ans;
    }
};
