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
    std::vector<std::vector<std::vector<std::set<std::pair<int, int>>>>> dp(n, std::vector<std::vector<std::set<std::pair<int, int>>>>(m, std::vector<std::set<std::pair<int, int>>>(4)));
    best[sr][sc][0] = 0;
    dp[sr][sc][0].emplace(sr, sc);
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
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] != '#') {
            if(best[nr][nc][d] > s + 1) {
                best[nr][nc][d] = s + 1;
                pq.push({s + 1, nr, nc, d});
                dp[nr][nc][d] = dp[r][c][d];
                dp[nr][nc][d].emplace(nr, nc);
            } else if(best[nr][nc][d] == s + 1) {
                dp[nr][nc][d].insert(dp[r][c][d].begin(), dp[r][c][d].end());
            }
        }

        for(int i = -1; i < 2; i += 2) {
            int nd = (d + i + 4) % 4;
            if(best[r][c][nd] > s + 1000) {
                best[r][c][nd] = s + 1000;
                pq.push({s + 1000, r, c, nd});
                dp[r][c][nd] = dp[r][c][d];
            } else if(best[r][c][nd] == s + 1000) {
                dp[r][c][nd].insert(dp[r][c][d].begin(), dp[r][c][d].end());
            }
        }
    }
    
    int64_t min_s = INF;
    std::set<std::pair<int, int>> s;
    for(int i = 0; i < 4; i++) {
        if(best[tr][tc][i] < min_s) {
            min_s = best[tr][tc][i];
            s = dp[tr][tc][i];
        } else if(best[tr][tc][i] == min_s) {
            s.insert(dp[tr][tc][i].begin(), dp[tr][tc][i].end());
        }
    }

    std::cout << s.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
