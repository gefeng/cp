#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <numeric>

constexpr int INF = int(2e9);

class Solution {
public:
    int minTravelTime(int l, int n, int k, std::vector<int>& position, std::vector<int>& time) {
        int ans = INF;
        int sum_t = std::accumulate(time.begin(), time.end(), 0);
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(k + 1, std::vector<int>(sum_t + 1, INF)));
        
        dp[0][0][time[0]] = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                for(int s = 0; s <= sum_t; s++) {
                    if(dp[i - 1][j][s] != INF) {
                        dp[i][j][time[i]] = std::min(dp[i][j][time[i]], dp[i - 1][j][s] + s * (position[i] - position[i - 1]));
                    }
                }
            
                int sum = time[i];
                int cnt = 0;
                for(int p = i - 1; p > 0; p--) {
                    sum += time[p];
                    cnt += 1;
                    for(int s = 0; s <= sum_t; s++) {
                        if(j - cnt >= 0 && dp[p - 1][j - cnt][s] != INF) {
                            dp[i][j][sum] = std::min(dp[i][j][sum], dp[p - 1][j - cnt][s] + s * (position[i] - position[p - 1]));
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i <= sum_t; i++) {
            ans = std::min(ans, dp[n - 1][k][i]);
        }
        
        return ans;
    }
};
