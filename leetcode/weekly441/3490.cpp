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
    int dfs(std::vector<int>& digits, int s, int p, int cur_s, int rem, int bounded, std::vector<std::vector<std::vector<std::vector<int>>>>& dp) {
        if(p == digits.size()) {
            return cur_s == s && rem == 0;
        }
        
        if(dp[bounded][p][cur_s][rem] != -1) {
            return dp[bounded][p][cur_s][rem];
        }
        
        int res = 0;
        int d = digits[p];
        if(bounded) {
            int ub = std::min(d, s - cur_s);
            for(int i = 0; i <= ub; i++) {
                res += dfs(digits, s, p + 1, cur_s + i, cur_s + i == 0 ? rem : (rem * i) % s, i == d, dp);
            }
        } else {
            int ub = std::min(9, s - cur_s);
            for(int i = 0; i <= ub; i++) {
                res += dfs(digits, s, p + 1, cur_s + i, cur_s + i == 0 ? rem : (rem * i) % s, 0, dp);
            }
        }
        
        return dp[bounded][p][cur_s][rem] = res;
    }
    
    int solve(int t) {
        if(t == 0) {
            return 0;
        }
        
        std::vector<int> digits;
        int x = t;
        int max_v = 0;
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
            max_v += 9;
        }
        std::reverse(digits.begin(), digits.end());
        
        int res = 0;
        int size = digits.size();
        
        for(int s = 1; s <= max_v; s++) {
            std::vector<std::vector<std::vector<std::vector<int>>>> dp(2, 
                    std::vector<std::vector<std::vector<int>>>(size, 
                        std::vector<std::vector<int>>(s + 1, std::vector<int>(s + 1, -1))));
            int cnt = dfs(digits, s, 0, 0, 1, 1, dp);
            res += cnt;
        }
        
        return res;
    }
    
    int beautifulNumbers(int l, int r) {
        int ans = solve(r) - solve(l - 1);
        return ans;
    }
};
