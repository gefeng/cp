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
    int maxFreeTime(int eventTime, int k, std::vector<int>& startTime, std::vector<int>& endTime) {
        int n = startTime.size();
        
        int64_t sum = 0;
        int64_t ans = 0;
        for(int l = 0, r = 0; r < n; r++) {
            sum += endTime[r] - startTime[r];
            
            if(r - l + 1 > k) {
                sum -= endTime[l] - startTime[l];
                l += 1;
            }
            
            if(r - l + 1 == k) {
                int pre = l == 0 ? 0 : endTime[l - 1];
                int nxt = r == n - 1 ? eventTime : startTime[r + 1];
                ans = std::max(ans, nxt - pre - sum);
            }
        }
        
        return ans;
    }
};
