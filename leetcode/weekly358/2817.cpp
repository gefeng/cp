#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    int minAbsoluteDifference(std::vector<int>& nums, int x) {
        int n = nums.size();
        std::set<int> s;
        
        int ans = INF;
        for(int i = x; i < n; i++) {
            s.insert(nums[i - x]);
            
            auto it = s.upper_bound(nums[i]);
            
            if(it != s.end()) {
                ans = std::min(ans, abs(*it - nums[i]));
            }
            if(it != s.begin()) {
                it--;
                ans = std::min(ans, abs(*it - nums[i]));
            }
        }
        
        return ans;
    }
};
