#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

constexpr int64_t INF = int64_t(2e18);

class Solution {
public:
    std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
        std::vector<int> ans;
        int n = intervals.size();
        
        for(int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        
        std::sort(intervals.begin(), intervals.end());
        
        auto cmp = [&](int i, int j) {
            return intervals[i][1] > intervals[j][1];
        };
        
        std::vector<std::vector<int64_t>> dp(5, std::vector<int64_t>(n + 1, -INF));
        std::vector<std::vector<std::vector<int>>> ds(5, std::vector<std::vector<int>>(n + 1));
        std::vector<int64_t> save_max(5, -INF);
        std::vector<std::vector<int>> save_seq(5);
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        
        save_max[0] = 0;
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && intervals[pq.top()][1] < intervals[i][0]) {
                int j = pq.top();
                
                pq.pop();
                for(int k = 0; k < 5; k++) {
                    if(dp[k][j + 1] > save_max[k]) {
                        save_max[k] = dp[k][j + 1];
                        save_seq[k] = ds[k][j + 1];
                    } else if(dp[k][j + 1] == save_max[k]) {
                        save_seq[k] = std::min(save_seq[k], ds[k][j + 1]);
                    }
                }
            }
            
            for(int k = 0; k < 5; k++) {
                if(save_max[k] > dp[k][i + 1]) {
                    dp[k][i + 1] = save_max[k];
                    ds[k][i + 1] = save_seq[k];
                } else if(save_max[k] == dp[k][i + 1]) {
                    ds[k][i + 1] = std::min(ds[k][i + 1], save_seq[k]);
                }
                
                if(k + 1 < 5 && save_max[k] != -INF) {
                    int64_t cand = save_max[k] + intervals[i][2];
                    if(cand > dp[k + 1][i + 1]) {
                        dp[k + 1][i + 1] = cand;
                        ds[k + 1][i + 1] = save_seq[k];
                        ds[k + 1][i + 1].push_back(intervals[i][3]);
                        std::sort(ds[k + 1][i + 1].begin(), ds[k + 1][i + 1].end());
                    } else if(cand == dp[k + 1][i + 1]) {
                        std::vector<int> s = save_seq[k];
                        s.push_back(intervals[i][3]);
                        std::sort(s.begin(), s.end());
                        ds[k + 1][i + 1] = std::min(ds[k + 1][i + 1], s);
                    }
                }
            }
            
            pq.push(i);
        }
        
        int64_t max_w = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 1; j <= n; j++) {
                if(dp[i][j] > max_w) {
                    ans = ds[i][j];
                    max_w = dp[i][j];
                } else if(dp[i][j] == max_w) {
                    ans = std::min(ans, ds[i][j]);
                }
            }
        }
        
        std::cout << max_w << '\n';
        
        return ans;
    }
};
