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
    int incremovableSubarrayCount(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int pre = -1;
                bool ok = true;
                for(int k = 0; k < n; k++) {
                    if(k < i || k > j) {
                        if(nums[k] <= pre) {
                            ok = false;
                            break;
                        }
                        pre = nums[k];
                    }
                }
                if(ok) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
