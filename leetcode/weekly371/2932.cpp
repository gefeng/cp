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
    int maximumStrongPairXor(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {   
            for(int j = i + 1; j < n; j++) {
                if(std::abs(nums[i] - nums[j]) <= std::min(nums[i], nums[j])) {
                    ans = std::max(nums[i] ^ nums[j], ans);
                }
            }
        }
        return ans;
    }
};
