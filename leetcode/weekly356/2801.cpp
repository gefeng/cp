#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)(1e9 + 7);

class Solution {
public:
    int countSteppingNumbers(std::string low, std::string high) {
        std::vector<int> digits1;
        std::vector<int> digits2;
        for(int i = 0; i < low.size(); i++) {
            digits1.push_back(low[i] - '0');    
        }
        for(int i = 0; i < high.size(); i++) {
            digits2.push_back(high[i] - '0');
        }
        
        std::vector<std::vector<std::vector<int64_t>>> dp1(2, std::vector<std::vector<int64_t>>(11, std::vector<int64_t>(digits1.size(), -1)));
        std::vector<std::vector<std::vector<int64_t>>> dp2(2, std::vector<std::vector<int64_t>>(11, std::vector<int64_t>(digits2.size(), -1)));
        int64_t x = dfs(digits1, 0, 1, 10, dp1);
        int64_t y = dfs(digits2, 0, 1, 10, dp2);
        x -= 1;
        y -= 1;
        x += MOD;
        y += MOD;
        x %= MOD;
        y %= MOD;
        
        auto is_stepping = [](std::string& s) {
            int n = s.size();
            for(int i = 1; i < n; i++) {
                if(abs(s[i] - s[i - 1]) != 1) {
                    return false;
                }
            }
            return true;
        };
        
        if(is_stepping(low)) {
            x -= 1;
            x += MOD;
            x %= MOD;
        }
        
        return (y - x + MOD) % MOD;
    }
    
    int64_t dfs(std::vector<int> digits, int i, int bounded, int pre, std::vector<std::vector<std::vector<int64_t>>>& dp) {
        int n = digits.size();
        if(i == n) {
            return 1;
        }
        if(dp[bounded][pre][i] != -1) {
            return dp[bounded][pre][i];
        }
        
        int64_t res = 0;
        if(pre == 10) {
            if(bounded) { 
                for(int d = 0; d < 10; d++) {
                    if(d > digits[i]) {
                        break;
                    }
                    if(d == digits[i]) {
                        res += dfs(digits, i + 1, 1, d, dp);
                        res %= MOD;
                    } else {
                        if(d == 0) {
                            res += dfs(digits, i + 1, 0, 10, dp);
                            res %= MOD;
                        } else {
                            res += dfs(digits, i + 1, 0, d, dp);
                            res %= MOD;
                        }
                    }
                }
            } else {
                for(int d = 0; d < 10; d++) {
                    if(d == 0) {
                        res += dfs(digits, i + 1, 0, 10, dp);
                        res %= MOD;
                    } else {
                        res += dfs(digits, i + 1, 0, d, dp);
                        res %= MOD;
                    }
                }
            }
        } else {
            int d1 = pre + 1;
            int d2 = pre - 1;
            if(d1 < 10) {
                if(bounded) {
                    if(d1 == digits[i]) {
                        res += dfs(digits, i + 1, 1, d1, dp);
                        res %= MOD;
                    } else if(d1 < digits[i]) {
                        res += dfs(digits, i + 1, 0, d1, dp);
                        res %= MOD;
                    }
                } else {
                    res += dfs(digits, i + 1, 0, d1, dp);
                    res %= MOD;
                }
            } 
            if(d2 >= 0) {
                if(bounded) {
                    if(d2 == digits[i]) {
                        res += dfs(digits, i + 1, 1, d2, dp);
                        res %= MOD;
                    } else if(d2 < digits[i]) {
                        res += dfs(digits, i + 1, 0, d2, dp);
                        res %= MOD;
                    }
                } else {
                    res += dfs(digits, i + 1, 0, d2, dp);
                    res %= MOD;
                }
            }
        }
        
        return dp[bounded][pre][i] = res;
    }
};
