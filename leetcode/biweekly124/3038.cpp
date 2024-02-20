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
    int maxOperations(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 2; i + 1 < n; i += 2) {
            if(nums[i] + nums[i + 1] == nums[0] + nums[1]) {
                ans += 1;
            } else {
                break;
            }
        }
        return ans;
    }
};
