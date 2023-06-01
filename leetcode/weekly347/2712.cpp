#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)1e18;

class Solution {
public:
    long long minimumCost(std::string s) {
        int n = s.size();
        std::vector<std::vector<LL>> dp1(n + 1, std::vector<LL>(2, INF));
        std::vector<std::vector<LL>> dp2(n + 1, std::vector<LL>(2, INF));
        dp1[0][0] = 0LL;
        dp1[0][1] = 0LL;
        dp2[0][0] = 0LL;
        dp2[0][1] = 0LL;
        
        for(int i = 1; i <= n; i++) {
            int c = s[i - 1] - '0';
            for(int j = 0; j < 2; j++) {
                if(j == c) {
                    dp1[i][j] = std::min(dp1[i][j], dp1[i - 1][j]);
                    dp1[i][j] = std::min(dp1[i][j], dp1[i - 1][j ^ 1] + i - 1);
                } else {
                    dp1[i][j] = std::min(dp1[i][j], dp1[i - 1][c] + i);   
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            int c = s[n - i] - '0';
            for(int j = 0; j < 2; j++) {
                if(j == c) {
                    dp2[i][j] = std::min(dp2[i][j], dp2[i - 1][j]);
                    dp2[i][j] = std::min(dp2[i][j], dp2[i - 1][j ^ 1] + i - 1);
                } else {
                    dp2[i][j] = std::min(dp2[i][j], dp2[i - 1][c] + i); 
                }
            }
        }
        
        LL ans = INF;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 2; j++) {
                //std::cout << i << ' ' << j << ' ' << dp1[i][j] << '\n';
                ans = std::min(ans, dp1[i][j] + dp2[n - i][j]);
            }
        }
        
        return ans;
    }
};
