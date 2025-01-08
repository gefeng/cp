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
    long long maximumCoins(std::vector<std::vector<int>>& coins, int k) {
        int n = coins.size();
        int64_t ans = 0;
        
        std::sort(coins.begin(), coins.end());
        
        auto solve = [&]() {
            int64_t sum = 0;
            for(int l = 0, r = 0; r < n; r++) {
                int len = coins[r][1] - coins[r][0] + 1;
                if(len >= k) {
                    ans = std::max(ans, int64_t(k) * coins[r][2]);
                    sum = 0;
                    l = r + 1;
                } else {
                    sum += int64_t(coins[r][2]) * (coins[r][1] - coins[r][0] + 1);
                    while(l < r && coins[r][1] - coins[l][0] + 1 > k) {
                        sum -= int64_t(coins[l][2]) * (coins[l][1] - coins[l][0] + 1);
                        l += 1;
                    }

                    ans = std::max(ans, sum);

                    int extra = k - (coins[r][1] - coins[l][0] + 1);
                    if(l && coins[l - 1][1] >= coins[l][0] - extra) {
                        ans = std::max(ans, sum + int64_t(coins[l - 1][2]) * (coins[l - 1][1] - coins[l][0] + extra + 1));
                    } 

                    if(r + 1 < n && coins[r][1] + extra >= coins[r + 1][0]) {
                        ans = std::max(ans, sum + int64_t(coins[r + 1][2]) * (std::min(coins[r][1] + extra, coins[r + 1][1]) - coins[r + 1][0] + 1));
                    }
                }
            }
        };
        
        solve();
        
        std::reverse(coins.begin(), coins.end());
        for(int i = 0; i < n; i++) {
            coins[i][0] *= -1;
            coins[i][1] *= -1;
            std::swap(coins[i][0], coins[i][1]);
        }
        
        solve();
        
        return ans;
    }
};
