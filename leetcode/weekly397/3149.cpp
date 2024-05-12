#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    void build(std::vector<std::vector<std::vector<int>>>& pre, int v, int mask, std::vector<int>& perm, std::vector<int>& ans) {
        perm.push_back(v);        
        if(pre[v][mask].empty()) {
            std::reverse(perm.begin(), perm.end());
            if(ans.empty() || ans > perm) {
                ans = perm;
            }
            std::reverse(perm.begin(), perm.end());
        } else {
            for(int x : pre[v][mask]) {
                build(pre, x, mask ^ (1 << v), perm, ans);
            }
        }
        perm.pop_back();
    }
    
    std::vector<int> findPermutation(std::vector<int>& nums) {
        std::vector<int> ans;
        int n = nums.size();
    
        std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, INF));
        std::vector<std::vector<std::vector<int>>> pre(n, std::vector<std::vector<int>>(1 << n));
        
        dp[0][1] = 0;
        
        int min_s = INF;
        for(int mask = 1; mask < (1 << n); mask++) {
            for(int r = 0; r < n; r++) {
                if(mask == (1 << n) - 1) {
                    dp[r][mask] += std::abs(r - nums[0]);
                    min_s = std::min(min_s, dp[r][mask]);
                    continue;
                }
                if(mask & (1 << r)) {
                    for(int i = 0; i < n; i++) {
                        if(mask & (1 << i)) {
                            continue;
                        }

                        int cost = std::abs(r - nums[i]);
                        int nxt_mask = mask | (1 << i);

                        if(dp[r][mask] + cost < dp[i][nxt_mask]) {
                            dp[i][nxt_mask] = dp[r][mask] + cost;
                            pre[i][nxt_mask].clear();
                            pre[i][nxt_mask].push_back(r);
                        } else if(dp[r][mask] + cost == dp[i][nxt_mask]) {
                            pre[i][nxt_mask].push_back(r);
                        }
                    }
                }
            }
        }

        for(int r = 0; r < n; r++) {
            if(dp[r][(1 << n) - 1] == min_s) {
                std::vector<int> perm;
                build(pre, r, (1 << n) - 1, perm, ans);
            }
        }
        
        return ans;
    }
};
