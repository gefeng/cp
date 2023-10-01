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
    long long maximumTripletValue(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::vector<int> save(n, 0);
        int max_v = 0;
        for(int i = n - 1; i >= 0; i--) {
            save[i] = max_v;
            max_v = std::max(max_v, nums[i]);
        }
        
        max_v = nums[0];
        for(int j = 1; j < n - 1; j++) {
            ans = std::max(ans, (int64_t)(max_v - nums[j]) * save[j]);
            max_v = std::max(max_v, nums[j]);
        }
        
        return ans;
    }
};
