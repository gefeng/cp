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

const int INF = (int)2e9;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            cost[i][i] = k;
            int len = 0;
            vector<int> cnt(n, 0);
            cnt[nums[i]] += 1;
            for(int j = i + 1; j < n; j++) {
                cnt[nums[j]] += 1;
                if(cnt[nums[j]] == 2) {
                    len += 2;
                } else if(cnt[nums[j]] > 2) {
                    len += 1;
                }
                cost[i][j] = len + k;
            }
        }
        
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
             
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j] + cost[i - j][i - 1]);
            }
        }
        
        return dp[n];
    }
};
