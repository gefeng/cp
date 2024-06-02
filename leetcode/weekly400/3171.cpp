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
    int minimumDifference(std::vector<int>& nums, int k) {
        int n = nums.size();
        int lo = 0;
        int hi = 1e9;
        int ans = -1;
        
        auto get_and = [](std::array<int, 30>& cnt_b, int len) {
            int res = 0;
            for(int i = 0; i < 30; i++) {
                if(cnt_b[i] == len) {
                    res |= 1 << i;
                }
            }
            return res;
        };
    
        auto bs = [&](int min_v, int max_v) {
            bool ok = false;
            std::array<int, 30> cnt_b{};
            for(int l = 0, r = 0; r < n; r++) {
                for(int j = 0; j < 30; j++) {
                    if(nums[r] & (1 << j)) {
                        cnt_b[j] += 1;
                    }
                }

                while(l <= r && get_and(cnt_b, r - l + 1) < min_v) {
                    for(int j = 0; j < 30; j++) {
                        if(nums[l] & (1 << j)) {
                            cnt_b[j] -= 1;
                        }
                    }
                    l += 1;
                }
                
                
                if(l <= r) {
                    int x = get_and(cnt_b, r - l + 1);
                    if(x >= min_v && x <= max_v) {
                        ok = true;
                        break;
                    }
                }
            }
            return ok;
        };
        
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            if(bs(k, mid + k) || bs(k - mid, k)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
