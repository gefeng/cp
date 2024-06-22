#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

class Solution {
public:
    int numberOfPermutations(int n, std::vector<std::vector<int>>& requirements) {
        int m = requirements.size();
        int max_c = 0;
        for(int i = 0; i < m; i++) {
            max_c = std::max(max_c, requirements[i][1]);
        }
        
        std::sort(requirements.begin(), requirements.end());
        
        if(requirements[0][0] == 0 && requirements[0][1] != 0) {
            return 0;
        }
        
        std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(max_c + 1, 0));
        dp[1][0] = 1;
        
        for(int i = 2; i <= n; i++) {
            auto it = std::lower_bound(requirements.begin(), requirements.end(), i - 1, [](const std::vector<int>& a, int x) {
                return a[0] < x;
            });
            
            if(it == requirements.end() || (*it)[0] != i - 1) {
                for(int j = 0; j <= max_c; j++) {
                    for(int k = 0; k < i; k++) {
                        if(i - k - 1 + j <= max_c) {
                            dp[i][i - k - 1 + j] += dp[i - 1][j];
                            dp[i][i - k - 1 + j] %= MOD;
                        }
                    }
                }
            } else {
                int j = (*it)[1];
                for(int k = 0; k < i; k++) {
                    if(j - (i - k - 1) >= 0) {
                        dp[i][j] += dp[i - 1][j - (i - k - 1)];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        
        return dp[n][requirements[m - 1][1]];
    }
};
