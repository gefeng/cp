#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

class Solution {
public:
    int minSizeSubarray(std::vector<int>& nums, int target) {
        int n = nums.size();
        int64_t sum = 0;
        
        for(int x : nums) {
            sum += x;
        }
        
        std::vector<int64_t> psum(n + 1, 0);
        std::map<int64_t, int64_t> m;
        m[0] = 0;
        int64_t ssum = 0;
        for(int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            ssum += nums[n - i];
            m[ssum] = i;
        }
        
        int64_t ans = INF;
        for(int i = 0; i <= n; i++) {
            int64_t x = target - psum[i];
            if(x < 0) {
                break;
            }
            
            int64_t rem = x % sum;
            int64_t cnt = x / sum;
            if(m.find(rem) != m.end()) {
                ans = std::min(ans, i + cnt * n + m[rem]);
            }
        }
        
        if(target <= sum) {
            m = std::map<int64_t, int64_t>();
            sum = 0;
            m[0] = -1;
            for(int i = 0; i < n; i++) {
                sum += nums[i];
                if(m.find(sum - target) != m.end()) {
                    ans = std::min(ans, i - m[sum - target]);
                }
                m[sum] = i;
            }
        }
        
        return ans == INF ? -1 : ans;
    }
};
