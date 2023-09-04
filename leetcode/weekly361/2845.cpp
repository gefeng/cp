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
    long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::map<int, int> m;
        m[0] = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) {
                cnt += 1;
            } 
            
            int x = (cnt % modulo) >= k ? (cnt % modulo) - k : modulo + (cnt % modulo) - k;
            ans += m[x];
            
            m[cnt % modulo] += 1;
        }
        
        return ans;
    }
};
