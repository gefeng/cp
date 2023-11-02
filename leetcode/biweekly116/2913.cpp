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
    int sumCounts(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            std::set<int> s;
            for(int j = i; j < n; j++) {
                s.insert(nums[j]);
                ans += s.size() * s.size();
            }
        }
        
        return ans;
    }
};
