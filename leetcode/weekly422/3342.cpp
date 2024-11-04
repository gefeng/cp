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

class Solution {
public:
    const std::array<int, 4> DR = {0, 1, 0, -1};
    const std::array<int, 4> DC = {1, 0, -1, 0};
    const int64_t INF = int64_t(2e18);
    
    int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[0] > b[0];
        };
        
        std::vector<std::vector<std::vector<int64_t>>> best(2, std::vector<std::vector<int64_t>>(n, std::vector<int64_t>(m, INF)));
        std::priority_queue<std::array<int64_t, 4>, std::vector<std::array<int64_t, 4>>, decltype(cmp)> pq(cmp);
        
        pq.push({0, 0, 0, 0});
        best[0][0][0] = 0;
        
        while(!pq.empty()) {
            std::array<int64_t, 4> now = pq.top();
            pq.pop();
            
            int64_t t = now[0];
            int r = now[1];
            int c = now[2];
            int f = now[3];
            
            if(best[f][r][c] != t) {
                continue;
            }
            
            for(int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                int nf = f ^ 1;
                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int64_t nt = std::max(t, int64_t(moveTime[nr][nc])) + (f == 0 ? 1 : 2);
                    if(nt < best[nf][nr][nc]) {
                        best[nf][nr][nc] = nt;
                        pq.push({nt, nr, nc, nf});
                    }
                }
            }
        }
        
        return std::min(best[0][n - 1][m - 1], best[1][n - 1][m - 1]);
    }
};
