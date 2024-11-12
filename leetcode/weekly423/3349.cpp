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
    bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int p = 0;
            for(int j = i + k; j < n && p < k; p++, j++) {
                if(i + p > i && (nums[i + p] <= nums[i + p - 1] || nums[j] <= nums[j - 1])) {
                    break;
                }
            }
            if(p == k) {
                return true;
            }
        }
        
        return false;
    }
};
