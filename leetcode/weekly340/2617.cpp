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
    int minimumVisitedCells(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<std::pair<int, int>>> g1(n, std::vector<std::pair<int, int>>(m));
        std::vector<std::vector<std::pair<int, int>>> g2(n, std::vector<std::pair<int, int>>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                g1[i][j] = {std::min(j + 1, m - 1), std::min(j + grid[i][j], m - 1)};
                g2[i][j] = {std::min(i + 1, n - 1), std::min(i + grid[i][j], n - 1)};
            }
        }
        
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::queue<std::pair<int, int>> q;
        
        q.emplace(0, 0);
        vis[0][0] = true;
        
        int cnt = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                std::pair<int, int> cur = q.front();
                q.pop();
                
                int r = cur.first;
                int c = cur.second;
                
                if(r == n - 1 && c == m - 1) {
                    return cnt;
                }
                
                int left = g1[r][c].first;
                int right = g1[r][c].second;
                
                for(int nc = left; nc <= right; nc++) {
                    int nr = r;
                    
                    if(!vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.emplace(nr, nc);
                        g1[nr][nc].first = std::max(g1[nr][nc].first, right);
                    }
                }
                
                int top = g2[r][c].first;
                int bot = g2[r][c].second;
                for(int nr = top; nr <= bot; nr++) {
                    int nc = c;
                    if(!vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.emplace(nr, nc);
                        g2[nr][nc].first = std::max(g2[nr][nc].first, bot);
                    }
                }
            }
            cnt += 1;
        }
        
        return -1;
    }
};
