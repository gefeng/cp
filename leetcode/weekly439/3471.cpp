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
    int largestInteger(std::vector<int>& nums, int k) {
        int ans = -1;
        int n = nums.size();
        
        std::vector<int> cnt(51, 0);
        std::vector<int> appear(51, 0);
        for(int l = 0, r = 0; r < n; r++) {
            cnt[nums[r]] += 1;
            if(r - l + 1 > k) {
                cnt[nums[l]] -= 1;
                l += 1;
            }
            if(r - l + 1 == k) {
                for(int i = 0; i <= 50; i++) {
                    if(cnt[i]) {
                        appear[i] += 1;
                    }
                }
            }
        }
        
        for(int i = 0; i <= 50; i++) {
            if(appear[i] == 1) {
                ans = i;
            }
        }
        
        return ans;
    }
};
