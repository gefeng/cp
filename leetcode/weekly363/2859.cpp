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
    int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }
        
        return ans;
    }
};
