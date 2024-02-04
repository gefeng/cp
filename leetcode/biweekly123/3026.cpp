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
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int64_t> psum(n + 1, 0);
        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        int64_t ans = -INF;
        std::map<int, int> m;
        for(int i = 0; i < n; i++) {
            for(int64_t j = -k; j <= k; j += k * 2) {
                int x = nums[i] + j;
                if(m.find(x) != m.end()) {
                    int pre = m[x];
                    ans = std::max(ans, psum[i + 1] - psum[pre]);
                }
                
                int64_t sum = psum[i];
                if(m.find(nums[i]) == m.end() || psum[m[nums[i]]] > sum) {
                    m[nums[i]] = i;
                }
            }
        }
        
        return ans == -INF ? 0 : ans;
    }
};
