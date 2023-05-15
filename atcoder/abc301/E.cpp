#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>

const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

constexpr int INF = (int)2e9;

void update_candy_graph(int H, int W, std::vector<std::string>& G, std::map<std::pair<int, int>, int>& m, 
        std::vector<std::vector<int>>& g, int sr, int sc) {
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist(H, std::vector<int>(W, INF));

    q.emplace(sr, sc);
    dist[sr][sc] = 0;

    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            std::pair<int, int> cur = q.front();
            q.pop();

            int r = cur.first;
            int c = cur.second;

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];

                if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] != '#' && dist[nr][nc] == INF) {
                    dist[nr][nc] = d + 1;
                    q.emplace(nr, nc);
                }
            }
        }

        d += 1;
    }

    int u = m[{sr, sc}];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(m.find({i, j}) != m.end()) {
                int v = m[{i, j}];
                g[u][v] = dist[i][j];
            }
        }
    }
}

void run_case() {
    int H, W, T;
    std::cin >> H >> W >> T;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    std::map<std::pair<int, int>, int> m;
    int generator = 1;

    int sr, sc;
    int tr, tc;
    int n = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == 'o') {
                m[{i, j}] = generator++;
                n += 1;
            }
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
                n += 1;
            }
            if(G[i][j] == 'G') {
                tr = i;
                tc = j;
                n += 1;
            }
        }
    }

    m[{sr, sc}] = 0;
    m[{tr, tc}] = n - 1;

    std::vector<std::vector<int>> g(n, std::vector<int>(n, INF));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] != '.' && G[i][j] != '#') {
                update_candy_graph(H, W, G, m, g, i, j); 
            }
        }
    }
    
    std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, INF));
    dp[0][1] = 0LL;

    for(int s = 1; s < (1 << n); s++) {
        for(int cur = 0; cur < n; cur++) {
            if(s & (1 << cur)) {
                for(int pre = 0; pre < n; pre++) {
                    if((s & (1 << pre)) && pre != cur && g[pre][cur] != INF && dp[pre][s ^ (1 << cur)] != INF) {
                        dp[cur][s] = std::min(dp[cur][s], dp[pre][s ^ (1 << cur)] + g[pre][cur]); 
                    }
                }
            }
        }
    }

    int ans = -1;
    for(int s = 0; s < (1 << n); s++) {
        if((s & 1) && dp[n - 1][s] <= T) {
            ans = std::max(ans, __builtin_popcount(s) - 2);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
