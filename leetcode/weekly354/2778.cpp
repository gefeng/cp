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
    int sumOfSquares(std::vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }
        
        return ans;
    }
};
