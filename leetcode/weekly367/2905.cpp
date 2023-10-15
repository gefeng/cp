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
    std::vector<int> findIndices(std::vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        std::vector<int> ans(2, -1);
        std::vector<int> save_min(n, 0);
        std::vector<int> save_max(n, 0);
        for(int i = 0; i < n; i++) {
            save_min[i] = i == 0 ? nums[i] : std::min(save_min[i - 1], nums[i]);
            save_max[i] = i == 0 ? nums[i] : std::max(save_max[i - 1], nums[i]);
            // x - pre >= valueDifference or pre - x >= valueDifference
            // pre <= x - valueDifference or pre >= x + valueDifference
            int j = i - indexDifference;
            if(j >= 0) {
                if(save_min[j] <= nums[i] - valueDifference || save_max[j] >= nums[i] + valueDifference) {
                    ans[1] = i;
                    for(int k = 0; k <= j; k++) {
                        if(nums[k] <= nums[i] - valueDifference || nums[k] >= nums[i] + valueDifference) {
                            ans[0] = k;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        return ans;
    }
};
