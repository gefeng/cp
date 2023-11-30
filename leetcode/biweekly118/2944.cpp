#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    int minimumCoins(std::vector<int>& prices) {
        int n = prices.size();
        
        std::vector<int> dp(n + 1, INF);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            int cost = prices[i - 1];
            
            for(int j = 0; j <= i; j++) {
                if(i + j <= n) {
                    dp[i + j] = std::min(dp[i + j], dp[i - 1] + cost);
                }
            }
        }
        
        return dp[n];
    }
};
