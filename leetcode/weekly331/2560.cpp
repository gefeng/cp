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
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        
        int lo = 1;
        int hi = (int)1e9;
        int ans = 0;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            vector<vector<int>> dp(2, vector<int>(n + 1, 0));
            for(int i = 1; i <= n; i++) {
                int x = nums[i - 1];
                if(x <= mid) {
                    dp[1][i] = max(dp[1][i], dp[0][i - 1] + 1);
                    if(i > 1) {
                        dp[1][i] = max(dp[1][i], dp[0][i - 2] + 1);
                        dp[1][i] = max(dp[1][i], dp[1][i - 2] + 1);
                    }
                } 
                
                dp[0][i] = max(dp[0][i], dp[0][i - 1]);
                dp[0][i] = max(dp[0][i], dp[1][i - 1]);
            }
            
            if(dp[0][n] >= k || dp[1][n] >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
