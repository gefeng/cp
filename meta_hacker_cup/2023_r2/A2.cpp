#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

int dfs(int H, int W, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, int r, int c, std::set<int>& s) {
    int cnt = 1;
    vis[r][c] = 1;
    
    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d]; 
        int nc = c + DC[d];
        if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
            if(G[nr][nc] == '.') {
                s.insert(nr * W + nc); 
            }

            if(G[nr][nc] == 'W' && !vis[nr][nc]) {
                cnt += dfs(H, W, G, vis, nr, nc, s); 
            }
        }
    }

    return cnt;
}

int bfs(int H, int W, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, int sr, int sc, std::set<int>& s) {
    std::queue<std::pair<int, int>> q;
    q.emplace(sr, sc);
    
    vis[sr][sc] = 1;
    int cnt = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [r, c] = q.front();
            q.pop();

            cnt += 1;
            
            for(int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                    if(G[nr][nc] == '.') {
                        s.insert(nr * W + nc); 
                    }

                    if(G[nr][nc] == 'W' && !vis[nr][nc]) {
                        q.emplace(nr, nc);
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
    }

    return cnt;
}

void run_case(int T) {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
    std::vector<std::pair<int, int>> pos;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == 'W' && !vis[i][j]) {
                std::set<int> s;
                int cnt = dfs(H, W, G, vis, i, j, s);
                if(s.size() == 1) {
                    pos.emplace_back(*s.begin(), cnt); 
                }
            }
        }
    }

    std::map<int, int> m;
    for(auto [p, f] : pos) {
        m[p] += f;
    }

    int ans = 0;
    for(auto [_, f] : m) {
        ans = std::max(ans, f);
    }

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
