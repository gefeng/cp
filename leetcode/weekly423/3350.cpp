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
    int maxIncreasingSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        
        std::vector<int> max_inc(n);
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && (i == j || nums[i] > nums[i - 1])) {
                i += 1;
            }
            int len = i - j;
            for(int k = j; k < i; k++) {
                max_inc[k] = len--;
            }
        }
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
            int len = max_inc[i];
            if(len + i < n && max_inc[len + i] >= len) {
                ans = std::max(ans, len);
            }
            ans = std::max(ans, len / 2);
        }
        
        return ans;
    }
};
