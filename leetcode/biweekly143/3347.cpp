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
    int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        std::vector<std::pair<int, int>> events;
        
        for(int i = 0; i < n; i++) {
            events.emplace_back(nums[i] - k, 0);
            events.emplace_back(nums[i] + k + 1, 1);
            events.emplace_back(nums[i], 2);
            events.emplace_back(nums[i] + 1, 3);
        }
        
        std::sort(events.begin(), events.end());
        
        int ans = 0;
        int cnt = 0;
        int cnt_origin = 0;
        for(int i = 0; i < n * 4; ) {
            int j = i;
            
            while(i < n * 4 && events[i].first == events[j].first) {
                if(events[i].second == 0) {
                    cnt += 1;
                } else if(events[i].second == 1) {
                    cnt -= 1;
                } else if(events[i].second == 2) {
                    cnt_origin += 1;
                } else {
                    cnt_origin -= 1;
                }
                i += 1;
            }
            
            ans = std::max(ans, std::min(cnt - cnt_origin, numOperations) + cnt_origin);
        }
        
        return ans;
    }
};
