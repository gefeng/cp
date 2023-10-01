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
        int64_t ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    ans = std::max(ans, (int64_t)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        
        return ans;
    }
};
