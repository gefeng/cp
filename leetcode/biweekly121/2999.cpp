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
    int64_t dfs(std::vector<int>& digits, int limit, std::string& s, int cur, int bounded, std::vector<std::vector<int64_t>>& dp) {
        int n = digits.size();
        if(cur == n) {
            return 1;
        }    
        
        if(dp[bounded][cur] != -1) {
            return dp[bounded][cur];
        }
        
        int64_t res = 0;
        if(n - cur <= s.size()) {
            if(!bounded) {
                res += dfs(digits, limit, s, cur + 1, bounded, dp);
            } else {
                int t = s[s.size() - (n - cur)] - '0';
                if(t == digits[cur]) {
                    res += dfs(digits, limit, s, cur + 1, bounded, dp);
                } else if(t < digits[cur]) {
                    res += dfs(digits, limit, s, cur + 1, 0, dp);
                }
            }
        } else {
            if(bounded) {
                int ed = std::min(limit, digits[cur]);
                if(ed == digits[cur]) {
                    res = dfs(digits, limit, s, cur + 1, 1, dp) + dfs(digits, limit, s, cur + 1, 0, dp) * ed;
                } else {
                    res = dfs(digits, limit, s, cur + 1, 0, dp) * (ed + 1);
                }
            } else {
                res = dfs(digits, limit, s, cur + 1, bounded, dp) * (limit + 1);
            }
        }
        
        return dp[bounded][cur] = res;
    }
    
    long long numberOfPowerfulInt(long long start, long long finish, int limit, std::string s) {
        auto get_digits = [](int64_t x) {
            std::vector<int> digits;
            while(x) {
                digits.push_back(x % 10);
                x /= 10;
            }
            std::reverse(digits.begin(), digits.end());
            return digits;
        };
        
        std::vector<int> d1 = get_digits(start - 1);
        std::vector<int> d2 = get_digits(finish);
        
        std::vector<std::vector<int64_t>> dp1(2, std::vector<int64_t>(d1.size(), -1));
        std::vector<std::vector<int64_t>> dp2(2, std::vector<int64_t>(d2.size(), -1));
        
        int64_t x = d2.size() < s.size() ? 0 : dfs(d2, limit, s, 0, 1, dp2);
        int64_t y = d1.empty() || d1.size() < s.size() ? 0 : dfs(d1, limit, s, 0, 1, dp1);
        return x - y;
    }
};
