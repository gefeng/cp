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
    int maxIncreasingGroups(std::vector<int>& usageLimits) {
        int n = usageLimits.size();
        
        std::sort(usageLimits.begin(), usageLimits.end(), std::greater<int>());
        
        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            int need = 0;
            int group = mid;
            for(int i = 0; i < n; i++) {
                need += group;
                need -= std::min(need, usageLimits[i]);
                group = std::max(0, group - 1);
            }
            
            if(group == 0 && need == 0) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
