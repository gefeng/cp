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
    std::vector<long long> findPrefixScore(std::vector<int>& nums) {
        int max_v = 0;
        LL sum = 0LL;
        int n = nums.size();
        std::vector<LL> ans(n, 0LL);
        
        for(int i = 0; i < n; i++) {
            max_v = std::max(max_v, nums[i]);
            sum += max_v + nums[i];
            ans[i] = sum;
        }
        
        return ans;
    }
};
