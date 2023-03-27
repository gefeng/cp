#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

class Solution {
public:
    std::vector<long long> minOperations(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::vector<LL> psum(n + 1, 0LL); 
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        
        std::vector<LL> ans;
        for(int q : queries) {
            auto it = upper_bound(nums.begin(), nums.end(), q);
            
            int i = it - nums.begin();
            
            LL sum_l = i == 0 ? 0LL : 1LL * i * q - psum[i];
            LL sum_r = i == n ? 0LL : psum[n] - psum[i] - 1LL * (n - i) * q;
            
            ans.push_back(sum_l + sum_r);
        }
        
        return ans;
    }
};
