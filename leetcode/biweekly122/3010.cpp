#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    int minimumCost(std::vector<int>& nums) {
        int n = nums.size();
        int min_v = INF;
    
        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                min_v = std::min(min_v, nums[0] + nums[j] + nums[k]);
            }
        }

        return min_v;
    }
};
