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

constexpr int INF = (int)1e9;
const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

class Solution {
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> save(n, std::vector<int>(n, INF));
        
        std::queue<std::pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.emplace(i, j);
                    save[i][j] = 0;
                }
            }
        }
        
        auto is_valid = [&](int r, int c) {
            return r >= 0 && c >= 0 && r < n && c < n;
        };
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [r, c] = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nr = r + DR[i];
                    int nc = c + DC[i];
                    if(is_valid(nr, nc) && save[nr][nc] > save[r][c] + 1) {
                        save[nr][nc] = save[r][c] + 1;
                        q.emplace(nr, nc);
                    }
                }
            }
        }
        
        auto cmp = [](const auto& a, const auto& b) {
            return a[2] < b[2];
        };
        
        std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, decltype(cmp)> pq(cmp);
        std::vector<std::vector<int>> best(n, std::vector<int>(n, 0));
        pq.push({0, 0, save[0][0]});
        best[0][0] = save[0][0];
        
        while(!pq.empty()) {
            std::array<int, 3> cur = pq.top();
            pq.pop();
            int r = cur[0];
            int c = cur[1];
            int d = cur[2];
            if(d != best[r][c]) {
                continue;
            }
            
            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                
                if(is_valid(nr, nc)) {
                    int nd = std::min(d, save[nr][nc]);
                    
                    if(nd > best[nr][nc]) {
                        best[nr][nc] = nd;
                        pq.push({nr, nc, nd});
                    }
                }
            }
        }
        
        return best[n - 1][n - 1];
    }
};
