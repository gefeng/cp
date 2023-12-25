#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

std::vector<std::string> G;

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

struct step {
    int r, c, d;
    std::vector<std::vector<int>> vis;
    step(int r, int c, int d, std::vector<std::vector<int>>& vis) : r(r), c(c), d(d), vis(vis) {}
};

int bfs1() {
    int n = G.size();
    int m = G[0].size();

    int sr, sc, tr, tc;
    for(int i = 0; i < m; i++) {
        if(G[0][i] == '.') {
            sr = 0;
            sc = i;
        }
        if(G[n - 1][i] == '.') {
            tr = n - 1;
            tc = i;
        }
    }

    auto is_valid = [&](int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m && G[r][c] != '#';
    };

    std::queue<step> q; 
    std::vector<std::vector<int>> best(n, std::vector<int>(m, 0));

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    vis[sr][sc] = 1;
    q.emplace(sr, sc, 0, vis);

    while(!q.empty()) {
        step cur = q.front();
        q.pop();
        int r = cur.r;
        int c = cur.c;
        int d = cur.d;
        std::vector<std::vector<int>>& v = cur.vis;

        if(r == tr && c == tc) {
            continue;
        }

        if(G[r][c] == '.') {
            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(is_valid(nr, nc) && !v[nr][nc] && best[nr][nc] < d + 1) {
                    best[nr][nc] = d + 1;
                    v[nr][nc] = 1;
                    q.emplace(nr, nc, d + 1, v);
                }
            }
        } else {
            char i = G[r][c];
            int nr = r;
            int nc = c;
            if(i == '^') {
                nr -= 1; 
            } else if(i == 'v') {
                nr += 1;
            } else if(i == '>') {
                nc += 1;
            } else if(i == '<') {
                nc -= 1;
            }

            if(is_valid(nr, nc) && !v[nr][nc] && best[nr][nc] < d + 1) {
                best[nr][nc] = d + 1;
                v[nr][nc] = 1;
                q.emplace(nr, nc, d + 1, v);
            }
        }
    }    


    return best[tr][tc];
}

void dfs(std::vector<std::vector<int>>& vis, int r, int c, int d, int tr, int tc, int& ans) {
    if(r == tr && c == tc) {
        ans = std::max(ans, d);
        return;
    } 

    int n = G.size();
    int m = G[0].size();
    vis[r][c] = 1;
    for(int i = 0; i < 4; i++) {
        int nr = r + DR[i];
        int nc = c + DC[i];
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && G[nr][nc] != '#') {
            dfs(vis, nr, nc, d + 1, tr, tc, ans);
        }
    }
    vis[r][c] = 0;
}

void run_case1() {
    std::cout << bfs1() << '\n';
}

void run_case2() {
    int n = G.size();
    int m = G[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] != '.' && G[i][j] != '#') {
                G[i][j] = '.';
            }
        }
    }

    int sr, sc, tr, tc;
    for(int i = 0; i < m; i++) {
        if(G[0][i] == '.') {
            sr = 0;
            sc = i;
        }
        if(G[n - 1][i] == '.') {
            tr = n - 1;
            tc = i;
        }
    }

    /*auto is_valid = [&](int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m && G[r][c] != '#';
    };

    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '.') {
                int cnt = 0;
                for(int d = 0; d < 4; d++) {
                    int ni = i + DR[d];
                    int nj = j + DC[d];
                    if(is_valid(ni, nj)) {
                        cnt += 1;
                    }
                }

                if(cnt > 3) {
                    res += 1;
                    std::cout << i << ' ' << j << '\n';
                    //std::cout << cnt << '\n';
                }
            }
        }
    }
    std::cout << res << '\n';*/
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    int ans = 0;
    dfs(vis, sr, sc, 0, tr, tc, ans);
    std::cout << ans << '\n';

    /*for(int i = 0; i < n; i++) {
        std::cout << G[i] << '\n';
    }*/
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }
    
    //run_case1();
    run_case2();
}
