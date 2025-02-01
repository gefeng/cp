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
    int maxFreeTime(int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
        int n = startTime.size();
        std::map<int, int> gap;
        
        int pre = 0;
        for(int i = 0; i < n; i++) {
            gap[startTime[i] - pre] += 1;
            pre = endTime[i];
        }
        gap[eventTime - pre] += 1;
        
        auto remove = [&](int x) {
            if(--gap[x] == 0) {
                gap.erase(x);
            }  
        };
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = i == 0 ? 0 : endTime[i - 1];
            int r = i == n - 1 ? eventTime : startTime[i + 1];
            int len = endTime[i] - startTime[i];
            
            ans = std::max(ans, r - l - len);
            
            remove(startTime[i] - l);
            remove(r - endTime[i]);
            auto it = gap.lower_bound(len);
            if(it != gap.end()) {
                ans = std::max(ans, r - l);
            }
            gap[startTime[i] - l] += 1;
            gap[r - endTime[i]] += 1;
        }
        
        return ans;
    }
};
