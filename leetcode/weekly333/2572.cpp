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

const LL MOD = (LL)1e9 + 7LL;

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> seen(31, false);
        vector<int> factor = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<bool> sq(31, false);
        vector<vector<bool>> save(31, vector<bool>(31, false));
        
        for(int i = 2; i * i < 31; i++) {
            sq[i * i] = true;
            for(int j = i * i * 2; j < 31; j += i * i) {
                sq[j] = true;
            }
        }
        
        for(int x : nums) {
            seen[x] = true;
            for(int f = 2; f <= x; f++) {
                if(x % f == 0) {
                    save[x][f] = true;
                }
            }
        }
        
        vector<vector<LL>> dp(n + 1, vector<LL>(1 << 10, -1LL));
        dp[0][0] = 1LL;
        for(int i = 1; i <= n; i++) {
            int v = nums[i - 1];
            for(int j = 0; j < (1 << 10); j++) {
                if(dp[i - 1][j] == -1) {
                    continue;
                }
                dp[i][j] = dp[i][j] == -1 ? dp[i - 1][j] : dp[i][j] + dp[i - 1][j];
                dp[i][j] %= MOD;

                
                if(sq[v]) {
                    continue;
                }
                
                bool ok = true;
                for(int k = 0; k < 10; k++) {
                    if(j & (1 << k)) {
                        if(save[v][factor[k]]) {
                            ok = false;
                            break;
                        }
                    }
                }
                
                if(ok) {
                    int nj = j;
                    for(int k = 0; k < 10; k++) {
                        if(v % factor[k] == 0) {
                            nj |= 1 << k;
                        } 
                    }
                    dp[i][nj] = dp[i][nj] == -1 ? dp[i - 1][j] : dp[i][nj] + dp[i - 1][j];
                    dp[i][nj] %= MOD;
                }
            }    
        }
        
        LL ans = 0LL;
        for(int i = 0; i < (1 << 10); i++) {
            if(dp[n][i] != -1) {
                //cout << i << ' ' << dp[n][i] << '\n';
                ans += dp[n][i];
                ans %= MOD;
            }
        }
        return ans - 1;
    }
};
