#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

class Solution {
public:
    std::string minCostGoodCaption(std::string caption) {
        int n = caption.size();
        std::string ans = "";
        
        std::vector<std::vector<std::vector<int>>> dp(4, std::vector<std::vector<int>>(26, std::vector<int>(n, INF)));
        
        for(int i = 0; i < 26; i++) {
            dp[1][i][n - 1] = std::abs(caption[n - 1] - 'a' - i);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 26; k++) {
                    if(dp[j][k][i + 1] != INF) {
                        int cost = std::abs(caption[i] - 'a' - k);
                        int nj = std::min(j + 1, 3);
                        dp[nj][k][i] = std::min(dp[nj][k][i], dp[j][k][i + 1] + cost);
                        
                        if(j == 3) {
                            for(int nk = 0; nk < 26; nk++) {
                                if(nk == k) {
                                    continue;
                                }
                                cost = std::abs(caption[i] - 'a' - nk);
                                dp[1][nk][i] = std::min(dp[1][nk][i], dp[j][k][i + 1] + cost);
                            }
                        }
                    }
                }
            }
        }
        
        int min_cost = INF;
        for(int i = 0; i < 26; i++) {
            min_cost = std::min(min_cost, dp[3][i][0]);
        }
        
        if(min_cost == INF) {
            return ans;
        }
        
        int p = 0;
        int pre = -1;
        while(ans.size() < n) {
            min_cost = INF;
            char now = -1;
            for(int i = 0; i < 26; i++) {
                if(i == pre) {
                    continue;
                }
                if(dp[3][i][p] < min_cost) {
                    now = i;
                    min_cost = dp[3][i][p];
                }
            }
            
            if(pre == -1) {
                pre = now;
                for(int i = 0; i < 3; i++) {
                    ans.push_back(char(now + 'a'));
                }
                p += 3;
                continue;
            }
            
            int j = -1;
            for(int i = 1; i <= 3; i++) {
                if(dp[i][pre][p] < min_cost || (dp[i][pre][p] == min_cost && pre < now)) {
                    min_cost = dp[i][pre][p];
                    j = i;
                    break;
                }
            }
            
            if(j != -1) {
                for(int i = 0; i < j; i++) {
                    ans.push_back(char(pre + 'a'));
                }
                p += j;
                continue;
            }
            
            for(int i = 0; i < 3; i++) {
                ans.push_back(char(now + 'a'));
                pre = now;
            }
            p += 3;
        }
        
        return ans;
    }
};
