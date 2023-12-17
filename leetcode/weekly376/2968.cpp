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
    int maxFrequencyScore(std::vector<int>& nums, long long k) {
        int n = nums.size();
        std::vector<int64_t> psum(n + 1, 0);
        
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            bool ok = false;
            for(int l = 0, r = 0; r < n; r++) {
                if(r - l + 1 > mid) {
                    l += 1;
                }
                if(r - l + 1 == mid) {
                    int i = (r + l) / 2;
                    int x = nums[i];
                    int64_t cost = (int64_t)x * (i - l + 1) - (psum[i + 1] - psum[l]) + psum[r + 1] - psum[i + 1] - (int64_t)x * (r - i);
                    if(cost <= k) {
                        ok = true;
                        break;
                    }
                }
            }
            
            if(ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
