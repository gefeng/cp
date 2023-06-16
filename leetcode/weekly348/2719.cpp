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

constexpr LL MOD = (LL)1e9 + 7LL;
constexpr int MAX = 300;

class Solution {
public:
    int count(std::string num1, std::string num2, int min_sum, int max_sum) {
        std::vector<int> digits1;
        std::vector<int> digits2;
        
        for(char c : num1) {
            digits1.push_back(c - '0');
        }
        for(char c : num2) {
            digits2.push_back(c - '0');
        }
        
        LL ans = (solve(digits2, min_sum, max_sum) - solve(digits1, min_sum, max_sum) + MOD) % MOD;
        
        int sum = 0;
        for(int d : digits1) {
            sum += d;
        }
        if(sum >= min_sum && sum <= max_sum) {
            ans += 1;
            ans %= MOD;
        }
        
        return ans;
    }

    LL solve(std::vector<int>& digits, int min_sum, int max_sum) {
        int n = digits.size();
        std::vector<std::vector<std::vector<LL>>> dp(2, std::vector<std::vector<LL>>(n, std::vector<LL>(MAX + 1, -1LL)));
        
        return dfs(digits, min_sum, max_sum, 0, 1, 0, dp);
    }
    
    LL dfs(std::vector<int>& digits, int min_sum, int max_sum, int cur, int bounded, int sum, 
           std::vector<std::vector<std::vector<LL>>>& dp) {
        int n = digits.size();
        
        if(cur == n) {
            return sum >= min_sum && sum <= max_sum ? 1LL : 0LL;
        }
        
        if(dp[bounded][cur][sum] != -1LL) {
            return dp[bounded][cur][sum];
        }
        
        LL res = 0LL;
        
        if(bounded) {
            res = dfs(digits, min_sum, max_sum, cur + 1, bounded, sum + digits[cur], dp);
            for(int d = 0; d < digits[cur]; d++) {
                res += dfs(digits, min_sum, max_sum, cur + 1, bounded ^ 1, sum + d, dp);
                res %= MOD;
            }
        } else {
            for(int d = 0; d < 10; d++) {
                res += dfs(digits, min_sum, max_sum, cur + 1, 0, sum + d, dp);
                res %= MOD;
            }
        }
        
        return dp[bounded][cur][sum] = res;
    }
};
