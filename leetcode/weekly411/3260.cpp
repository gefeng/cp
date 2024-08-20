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
    int dfs(int n, int k, std::vector<int>& rem, int now, int r, std::vector<std::vector<int>>& dp, std::string& ans) {
        if(n % 2 == 1 && now == n / 2) {
            for(int i = 9; i >= 0; i--) {
                if(((i * rem[n / 2] % k) + r) % k == 0) {
                    ans.push_back((char)(i + '0'));
                    return 1;
                }
            }
            return 0;
        }
        if(n % 2 == 0 && now < n / 2) {
            return r == 0;
        }
        
        if(dp[now][r] != -1) {
            return dp[now][r];
        }
        
        int ed = now == n - 1 ? 1 : 0;
        for(int i = 9; i >= ed; i--) {
            ans.push_back((char)(i + '0'));
            int nr = ((i * rem[now] % k) + (i * rem[n - 1 - now] % k)) % k;
            nr += r;
            nr %= k;
            if(dfs(n, k, rem, now - 1, nr, dp, ans)) {
                return 1;
            }
            ans.pop_back();
        }
        return dp[now][r] = 0;
    }

    std::string largestPalindrome(int n, int k) {
        std::vector<int> rem(n, 0);
        
        for(int i = 0, j = 1; i < n; i++) {
            rem[i] = j % k;
            j *= 10;
            j %= k;
        }
        
        std::string ans = "";
        std::vector<std::vector<int>> dp(n, std::vector<int>(10, -1));
        dfs(n, k, rem, n - 1, 0, dp, ans);
        
        std::string tmp = ans.substr(0, n % 2 == 1 ? ans.size() - 1 : ans.size());
        std::reverse(tmp.begin(), tmp.end());
        
        ans.append(tmp);
        
        return ans;
    }
};
