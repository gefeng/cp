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
    const int INF = (int)1e9;
public:
    int minimumChanges(std::string s, int K) {
        int n = s.size();
        std::vector<std::vector<int>> divisors(n + 1);
        std::vector<std::vector<int>> save(n, std::vector<int>(n, INF));
        
        for(int i = 1; i <= n; i++) {
            for(int d = 1; d < i; d++) {
                if(i % d == 0) {
                    divisors[i].push_back(d);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = j - i + 1;
                int min_c = INF;
                std::vector<int>& div = divisors[len];
                for(int d : div) {
                    if(len % d == 0) {
                        int cnt = 0;
                        for(int k = 0; k < d; k++) {
                            for(int l = i + k, r = j - d + 1 + k; l < r; l += d, r -= d) {
                                if(s[l] != s[r]) {
                                    cnt += 1;
                                }
                            }
                        }
                        
                        min_c = std::min(min_c, cnt);
                    }
                }
                
                save[i][j] = min_c;
            }
        }
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(K + 1, INF));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                int cost = save[i - j][i - 1];
                for(int k = 1; k <= K; k++) {
                    if(k - 1 <= i - j) {
                        dp[i][k] = std::min(dp[i][k], dp[i - j][k - 1] + cost);
                    }
                }
            }
        }
        
        return dp[n][K];
    }
};
