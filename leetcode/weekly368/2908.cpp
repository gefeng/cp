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
    const int INF = (int)2e9;
public:
    int minimumSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> save_min(n, 0);
        
        int min_v = nums[0];
        for(int i = 1; i < n; i++) {
            save_min[i] = min_v;
            min_v = std::min(min_v, nums[i]);
        }
        
        min_v = nums.back();
        int ans = INF;
        for(int i = n - 2; i > 0; i--) {
            if(nums[i] > save_min[i] && nums[i] > min_v) {
                ans = std::min(ans, nums[i] + save_min[i] + min_v);
            }
            min_v = std::min(min_v, nums[i]);
        }
        
        return ans == INF ? -1 : ans;
    }
};
