#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    int maxAdjacentDistance(std::vector<int>& nums) {
        int n = nums.size();
        int ans = -INF;
        
        for(int i = 0; i < n; i++) {
            ans = std::max(ans, std::abs(nums[i] - nums[(i + 1) % n]));
        }
        
        return ans;
    }
};
