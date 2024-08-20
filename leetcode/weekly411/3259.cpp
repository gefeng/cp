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
    long long maxEnergyBoost(std::vector<int>& energyDrinkA, std::vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(2, 0));
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + energyDrinkA[i - 1];
            dp[i][1] = dp[i - 1][1] + energyDrinkB[i - 1];
            
            if(i > 1) {
                dp[i][0] = std::max(dp[i][0], dp[i - 2][1] + energyDrinkA[i - 1]);
                dp[i][1] = std::max(dp[i][1], dp[i - 2][0] + energyDrinkB[i - 1]);
            }
        }
        
        return std::max(dp[n][0], dp[n][1]);
    }
};
