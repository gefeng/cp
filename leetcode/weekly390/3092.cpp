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
    std::vector<long long> mostFrequentIDs(std::vector<int>& nums, std::vector<int>& freq) {
        int n = nums.size();
        std::map<int64_t, int64_t> m1;
        std::map<int64_t, int64_t> m2;
        
        std::vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int64_t pre = m1[nums[i]];
            
            if(--m2[pre] == 0) {
                m2.erase(pre);
            }
            
            m1[nums[i]] += freq[i];
            m2[pre + freq[i]] += 1;
            
            ans[i] = m2.rbegin()->first;
        }
        
        return ans;
    }
};
