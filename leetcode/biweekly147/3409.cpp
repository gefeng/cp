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
    int longestSubsequence(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int max_v = *std::max_element(nums.begin(), nums.end());
        
        std::vector<std::vector<int>> dp(max_v + 1, std::vector<int>(max_v + 1, -1));
        std::vector<std::vector<int>> ds(max_v + 1, std::vector<int>(max_v + 1, -1));
        
        for(int i = 0; i < n; i++) {
            int v = nums[i];
            
            if(ds[v][max_v] == -1) {
                dp[v][max_v] = 1;
                dp[v][0] = 1;
                ds[v][max_v] = 1;
                ds[v][0] = 1;
            } else {
                ds[v][0] = std::max(ds[v][0] + 1, 2);
            }
            
            for(int j = 1, k = max_v - 1; j < v; j++) {
                int d = v - j;
                while(k >= 0 && k > d) {
                    k -= 1;
                }
                if(dp[j][k] != -1) {
                    ds[v][d] = std::max(ds[v][d], dp[j][k] + 1);
                } else if(ds[j][max_v] != -1) {
                    ds[v][d] = std::max(ds[v][d], 2);
                }
            }
            for(int j = max_v, k = max_v - 1; j > v; j--) {
                int d = j - v;
                while(k >= 0 && k > d) {
                    k -= 1;
                }
                if(dp[j][k] != -1) {
                    ds[v][d] = std::max(ds[v][d], dp[j][k] + 1);
                } else if(ds[j][max_v] != -1) {
                    ds[v][d] = std::max(ds[v][d], 2);
                }
            }
            
            if(max_v != 1 && dp[v][1] != -1) {
                ds[v][0] = std::max(ds[v][0], dp[v][1] + 1);
            }
            
            for(int j = max_v - 1; j >= 0; j--) {
                if(j == max_v - 1) {
                    dp[v][j] = ds[v][j];
                } else {
                    dp[v][j] = std::max(dp[v][j + 1], ds[v][j]);
                }
            }
        }
        
        for(int i = 0; i <= max_v; i++) {
            for(int j = 0; j <= max_v; j++) {
                ans = std::max(ans, ds[i][j]);
            }
        }
        return ans;
    }
};
