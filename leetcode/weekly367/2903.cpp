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
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(j - i >= indexDifference && std::abs(nums[i] - nums[j]) >= valueDifference) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        
        return ans;
    }
};
