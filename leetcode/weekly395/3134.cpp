#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = int(1e5);

class Solution {
public:
    int medianOfUniquenessArray(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int lo = 1;
        int hi = n;
        int64_t tot = int64_t(n + 1) * n / 2;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            int64_t cnt = 0;
            std::vector<int> freq(MAX + 1, 0);
            int unique = 0;
            for(int l = 0, r = 0; r < n; r++) {
                if(++freq[nums[r]] == 1) {
                    unique += 1;
                }
                
                while(unique > mid) {
                    if(--freq[nums[l]] == 0) {
                        unique -= 1;
                    }
                    l += 1;
                }
                
                cnt += r - l + 1;
            }
            
            int64_t need = (tot + 1) / 2;
            if(cnt >= need) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } 
        
        return ans;
    }
};
