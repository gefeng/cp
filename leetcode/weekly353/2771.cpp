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
    int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));

        dp[1][0] = 1;
        dp[1][1] = 1;
        int ans = 1;
        for(int i = 2; i <= n; i++) {
            int v1 = nums1[i - 1];
            int v2 = nums2[i - 1];
            int pv1 = nums1[i - 2];
            int pv2 = nums2[i - 2];
            
            if(v1 >= pv1) {
                dp[i][0] = std::max(dp[i][0], dp[i - 1][0] + 1);
            } else {
                dp[i][0] = std::max(dp[i][0], 1);
            }
            
            if(v1 >= pv2) {
                dp[i][0] = std::max(dp[i][0], dp[i - 1][1] + 1);
            } else {
                dp[i][0] = std::max(dp[i][0], 1);
            }
            
            if(v2 >= pv2) {
                dp[i][1] = std::max(dp[i][1], dp[i - 1][1] + 1);
            } else {
                dp[i][1] = std::max(dp[i][1], 1);
            }
            
            if(v2 >= pv1) {
                dp[i][1] = std::max(dp[i][1], dp[i - 1][0] + 1);
            } else {
                dp[i][1] = std::max(dp[i][1], 1);
            }
            
            ans = std::max(ans, std::max(dp[i][0], dp[i][1]));
        }
        
        return ans;
    }
};
