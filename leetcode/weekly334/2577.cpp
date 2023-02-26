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

using namespace std;

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};
const int INF = (int)2e9;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[2] > b[2];
        };
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> dp(m, vector<int>(n, INF));
        
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        
        while(!pq.empty()) {
            array<int, 3> cur = pq.top();
            pq.pop();
            
            int r = cur[0];
            int c = cur[1];
            int t = cur[2];
            
            if(dp[r][c] != t) {
                continue;
            }
            
            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                int nt = 0;
                if(nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    if(t < grid[nr][nc] - 1) {
                        nt = t + (grid[nr][nc] - t - 1 + 2 - 1) / 2 * 2 + 1;
                    } else {
                        nt = t + 1;
                    }
                    
                    if(dp[nr][nc] > nt) {
                        pq.push({nr, nc, nt});
                        dp[nr][nc] = nt;
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
