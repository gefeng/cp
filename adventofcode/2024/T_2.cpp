#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int MAX_C = 20;
constexpr int INF = int(2e9);
constexpr int SAVE = 100;

void dfs(int n, int m, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, std::vector<std::vector<std::vector<int>>>& seen,  
        int r, int c, int d, std::set<std::pair<int, int>>& dest) {
    seen[d][r][c] = 1;
    if(G[r][c] == '.') {
        dest.emplace(r, c);
    }

    for(int i = 0; i < 4; i++) {
        int nr = r + DR[i];
        int nc = c + DC[i]; 
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && d + 1 <= MAX_C && !seen[d + 1][nr][nc]) {
            dfs(n, m, G, vis, seen, nr, nc, d + 1, dest);
        }
    }
}

void run_case() {
    std::vector<std::string> G;
    for(std::string S; std::getline(std::cin, S); ) {
        G.push_back(S); 
    }

    int n = G.size();
    int m = G[0].size();

    int sr = -1;
    int sc = -1;
    int tr = -1;
    int tc = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
                G[i][j] = '.';
            }
            if(G[i][j] == 'E') {
                tr = i;
                tc = j;
                G[i][j] = '.';
            }
        }
    }

    auto bfs_1 = [&](int sx, int sy, int tx, int ty) {
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> time(n, std::vector<int>(m, INF));
        q.emplace(sx, sy);
        time[sx][sy] = 0;
        
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if(r == tx && c == ty) {
                break;
            }
            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];        
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] != '#' && time[nr][nc] == INF) {
                    time[nr][nc] = time[r][c] + 1; 
                    q.emplace(nr, nc);
                }
            } 
        }
        return time[tx][ty];
    };

    auto dist = [](int x_1, int y_1, int x_2, int y_2) {
        return std::abs(x_1 - x_2) + std::abs(y_1 - y_2);
    };

    int t = bfs_1(sr, sc, tr, tc);
    std::vector<std::vector<int>> to_end(n, std::vector<int>(m, INF));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '.') {
                to_end[i][j] = bfs_1(i, j, tr, tc);
            }
        }
    }

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    int r = sr;
    int c = sc;
    int ans = 0;
    int d = 0;

    while(r != tr || c != tc) {
        vis[r][c] = 1;
        std::set<std::pair<int, int>> dest;
        std::vector<std::vector<std::vector<int>>> s(MAX_C + 1, std::vector<std::vector<int>>(n, std::vector<int>(m, 0)));
        dfs(n, m, G, vis, s, r, c, 0, dest);
        
        for(auto [nr, nc] : dest) {
            int tx = d + to_end[nr][nc] + dist(r, c, nr, nc);
            if(t - tx >= SAVE) {
                ans += 1;
            }
        }
        for(int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] == '.' && !vis[nr][nc]) {
                r = nr;
                c = nc;
                break;
            }
        }
        d += 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
