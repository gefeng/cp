#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int64_t INF = int64_t(2e18);

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
            }
            if(G[i][j] == 'E') {
                tr = i;
                tc = j;
            }
        }
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[0] > b[0];
    };

    std::priority_queue<std::array<int64_t, 4>, std::vector<std::array<int64_t, 4>>, decltype(cmp)> pq(cmp);
    std::vector<std::vector<std::vector<int64_t>>> best(n, std::vector<std::vector<int64_t>>(m, std::vector<int64_t>(4, INF)));
    best[sr][sc][0] = 0;
    pq.push({0, sr, sc, 0});
    
    while(!pq.empty()) {
        std::array<int64_t, 4> now = pq.top();
        pq.pop();
        int64_t s = now[0];
        int r = now[1];
        int c = now[2];
        int d = now[3];
        
        if(best[r][c][d] != s || (r == tr && c == tc)) {
            continue;
        }

        int nr = r + DR[d];
        int nc = c + DC[d];
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] != '#' && best[nr][nc][d] > s + 1) {
            best[nr][nc][d] = s + 1;
            pq.push({s + 1, nr, nc, d});
        }

        int nd = (d + 1) % 4;
        if(best[r][c][nd] > s + 1000) {
            best[r][c][nd] = s + 1000;
            pq.push({s + 1000, r, c, nd});
        }

        nd = (d - 1 + 4) % 4;
        if(best[r][c][nd] > s + 1000) {
            best[r][c][nd] = s + 1000;
            pq.push({s + 1000, r, c, nd});
        }
    }
    
    int64_t ans = INF;
    for(int i = 0; i < 4; i++) {
        ans = std::min(ans, best[tr][tc][i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
