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
    bool checkArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int64_t> diff(n + 1, 0);
        
        int64_t sum = 0;
        for(int i = 0; i < n; i++) {
            sum += diff[i];
            
            if(nums[i] < sum) {
                return false;
            }
            
            nums[i] -= sum;
            
            if(i <= n - k) {
                diff[i + 1] += nums[i];
                diff[std::min(i + k, n)] -= nums[i];
            } else {
                if(nums[i] != 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
