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
    int maximizeTheProfit(int n, std::vector<std::vector<int>>& offers) {
        int m = offers.size();
        
        std::sort(offers.begin(), offers.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        std::vector<int> dp(m + 1, 0);
        for(int i = 1; i <= m; i++) {
            auto it = std::lower_bound(offers.begin(), offers.begin() + i, offers[i - 1][0], [](const auto& t, int v) {
                return t[1] < v;
            });
            
            if(it == offers.begin()) {
                dp[i] = std::max(dp[i - 1], offers[i - 1][2]);
            } else {
                it--;
                int j = it - offers.begin() + 1;
                dp[i] = std::max(dp[i - 1], dp[j] + offers[i - 1][2]);
            }
        }
        
        return dp[m];
    }
};
