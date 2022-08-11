#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            dp[i] |= nums[i - 1] == nums[i - 2] && dp[i - 2];
            if(i >= 3) {
                dp[i] |= nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3] && dp[i - 3];
                dp[i] |= nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1 && dp[i - 3];
            }
        }
        
        return dp[n];
    }
};
