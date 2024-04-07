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
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] > nums[j - 1]) {
                    cnt += 1;
                } else {
                    break;
                }
            }
            
            ans = std::max(ans, cnt);
            
            cnt = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[j - 1]) {
                    cnt += 1;
                } else {
                    break;
                }
            }
            
            ans = std::max(ans, cnt);
        }
        
        return ans;
    }
};
