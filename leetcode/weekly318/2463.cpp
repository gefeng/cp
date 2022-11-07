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
using LL = long long;

class Solution {
    const LL INF = (LL)2e18;
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {    
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
    
        int n = robot.size();
        int m = factory.size();
        vector<vector<LL>> dp(n + 1, vector<LL>(m + 1, INF));
    
        for(int i = 0; i <= m; i++) {
            dp[0][i] = 0LL;
        }
        
        vector<int> psum(m + 1, 0);
        for(int i = 1; i <= m; i++) {
            psum[i] = psum[i - 1] + factory[i - 1][1];    
        }
        
        vector<vector<LL>> dist(m, vector<LL>(n + 1, 0LL));
        for(int i = 0; i < m; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = dist[i][j - 1] + abs(robot[j - 1] - factory[i][0]);
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {                
                for(int k = 0; k <= factory[j - 1][1]; k++) {
                    if(i - k >= 0 && psum[j - 1] >= i - k) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dist[j - 1][i] - dist[j - 1][i - k]);
                    }
                }
            }
        }
        
        LL ans = INF;
        for(int i = 1; i <= m; i++) {
            ans = min(ans, dp[n][i]);
        }
        return ans;
    }
};
