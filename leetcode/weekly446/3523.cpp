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
    int maximumPossibleSize(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int j = i;
            while(i + 1 < n && nums[i + 1] < nums[j]) {
                i += 1;
            }
            ans += 1;
        }
        
        return ans;
    }
};
