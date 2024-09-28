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
    long long maximumTotalSum(std::vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        int64_t ans = 0;
        
        std::sort(maximumHeight.begin(), maximumHeight.end());
        
        int h = maximumHeight.back();
        ans = h;
        for(int i = n - 2; i >= 0; i--) {
            h = std::min(h - 1, maximumHeight[i]);
            if(h == 0) {
                ans = -1;
                break;
            }
            ans += h;
        }
        
        return ans;
    }
};
