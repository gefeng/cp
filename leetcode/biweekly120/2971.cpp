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
    long long largestPerimeter(std::vector<int>& nums) {
        int64_t ans = -1;
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        int64_t sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            if(i) {
                auto it = std::lower_bound(nums.begin() + i + 1, nums.end(), sum);
                int j = it - nums.begin();
                j -= 1;
                if(j > i && j < n) {
                    ans = std::max(ans, sum + nums[j]);
                }
            }
        }
        
        return ans;
    }
};
