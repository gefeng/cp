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
    int minOperations(std::vector<int>& nums, int k) {
        int ans = 0;
        std::sort(nums.begin(), nums.end());
        for(int x : nums) {
            if(x < k) {
                ans += 1;
            }
        }
        return ans;
    }
};
