#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9) + 10;

class Solution {
public:
    int maxDistinctElements(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end());
        
        int last = -INF;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = nums[i] - k;
            int r = nums[i] + k;
            if(l > last) {
                last = l;
                ans += 1;
            } else {
                if(r > last) {
                    last += 1;
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
