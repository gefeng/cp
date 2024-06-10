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
    int maxTotalReward(std::vector<int>& rewardValues) {
        int n = rewardValues.size();
        
        std::sort(rewardValues.begin(), rewardValues.end());
        
        int max_v = rewardValues.back();
        std::vector<int> dp(max_v * 3, 0);
        dp[0] = 1;
        
        
        for(int i = 0; i < max_v; i++) {
            if(dp[i]) {
                int j = std::upper_bound(rewardValues.begin(), rewardValues.end(), i) - rewardValues.begin();
                for(int k = j; k < n; k++) {
                    dp[i + rewardValues[k]] = 1;
                }
            }
        }
        
        int ans = 0;
        for(int i = dp.size() - 1; i >= 0; i--) {
            if(dp[i]) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
