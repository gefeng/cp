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
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum |= nums[j];
                if(sum >= k) {
                    ans = ans == -1 ? j - i + 1 : std::min(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
