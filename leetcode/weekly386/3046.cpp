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
    bool isPossibleToSplit(std::vector<int>& nums) {
        int n = nums.size();
        std::array<int, 200> cnt = {};
        for(int i = 0; i < n; i++) {
            if(++cnt[nums[i]] > 2) {
                return false;
            }
        }
        
        return true;
    }
};
