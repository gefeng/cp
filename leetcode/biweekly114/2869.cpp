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
    int minOperations(std::vector<int>& nums, int k) {
        std::set<int> s;
        int ans = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] <= k) {
                s.insert(nums[i]);
            }
            ans += 1;
            if(s.size() == k) {
                break;
            }
        }
        
        return ans;
    }
};
